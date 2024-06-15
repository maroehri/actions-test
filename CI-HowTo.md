# Continuous Integration-Demo mit GitHub Actions

Die Demo verwendet ein Beispiel-Projekt für eine Fahrtenbuch-App in C++. Der
Code dazu ist gehostet unter

```text
https://github.com/maroehri/actions-test.git
```

## GitHub Actions

Die GitHub Actions-Datei `ci.yaml` definiert eine Continuous Integration (CI)
Pipeline für ein C++ Projekt. Die Pipeline führt verschiedene Überprüfungen und
Builds aus, wenn Code in den `main` Branch gepusht oder ein Pull Request
erstellt wird.

### Trigger

Die Pipeline wird bei Push-Events und Pull Requests auf den `main` Branch
ausgelöst.

### Jobs

1. Format-Check

    Dieser Job stellt sicher, dass der gesamte C++ Code einheitlich formatiert
    ist. Dies hilft, den Code sauber und lesbar zu halten und verhindert
    Formatierungsprobleme, die durch unterschiedliche Entwicklungsumgebungen
    entstehen könnten.

    Der Job führt hierfür `clang-format` aus, um den Code-Stil zu überprüfen und
    ggf. zu korrigieren. Die Regeln dazu befinden sich in der Datei
    `.clang-format` des Repositorys.

2. Cppcheck-Analyse

    Dieser Job führt eine statische Code-Analyse mit dem Tool `cppcheck` durch.
    `cppcheck` überprüft den Code auf gängige Fehler wie z.B. Pufferüberläufe,
    nicht initialisierte Variablen und mögliche Nullzeiger-Dereferenzierungen.

    Anschließend wird ein Bericht erstellt und unter dem Namen
    `cppcheck_report.txt` abgelegt.

3. Statische Analyse

    Mit `clang-tidy` wird eine weitere statische Analyse durchgeführt.
    `clang-tidy` ist ein leistungsfähiges Tool, das nicht nur einfache Fehler,
    sondern auch komplexere Probleme und Anti-Pattern im Code erkennen kann.

    Die Regeln hierfür befinden sich in der Datei `.clang-tidy` des Repositorys.

4. Build

    Dieser Job kompiliert das gesamte Projekt gemäß dem im Repository
    befindlichen `Makefile`, um sicherzustellen, dass der Code fehlerfrei gebaut
    werden kann. Dies umfasst das Übersetzen der Quellcode-Dateien und das
    Erstellen der ausführbaren Dateien oder Bibliotheken.

5. Test

    Der Test-Job führt alle definierten Tests im Projekt aus. Hierzu wird
    ebenfalls das im Repository befindliche `Makefile` verwendet, um die Tests
    zu bauen. Dies umfasst in diesem Beispiel-Projekt nur Unit-Tests, könnte
    aber auch Integrationstests und möglicherweise andere Arten von Tests
    beinhalten.

    Das Ergebnis der Tests wird in einer Datei `test_results.xml` abgelegt und
    an eine `JUnit Report Action` zur besseren Veranschaulichung weitergeleitet.

## HowTo - Anwenden und Demonstrieren

Die enthaltene Datei `ci.yaml` muss im Wurzelverzeichnis des Git-Repositories
angelegt worden sein: `.github/workflows/ci.yaml`

Sobald dann eine Datei in den `main` Branch gepusht oder in einen Pull Request
integriert wird, wird die Pipeline automatisch ausgelöst. Die Ergebnisse jedes
Jobs können in der GitHub Actions Sektion des Repositories eingesehen werden.
Artefakte wie Berichte und Testergebnisse können heruntergeladen und überprüft
werden. Wenn ein Job fehlschlägt, zeigt GitHub Actions den spezifischen Schritt
und die Fehlermeldung an.

### Beispiele für das Provozieren von Fehlern

1. **Format-Check Fehler**

   * **Beispiel**: Verändern Sie den Code in einer Weise, die nicht den
     Formatierungsrichtlinien entspricht.
   * **Provozieren**: Fügen Sie zusätzliche Leerzeichen oder Tabs hinzu, oder
     ändern Sie die Einrückung in einer C++-Datei.
   * **Erwartetes Ergebnis**: Der `format-check`-Job schlägt fehl, und
     `clang-format` zeigt die Unterschiede an.

2. **Cppcheck-Analyse Fehler**

   * **Beispiel**: Fügen Sie Code hinzu, der typische Fehler enthält, wie z.B.
     uninitialisierte Variablen oder mögliche Nullzeiger-Dereferenzierungen.
   * **Provozieren**: Schreiben Sie eine Funktion, die eine Variable verwendet,
     bevor sie initialisiert wurde.
   * **Erwartetes Ergebnis**: Der `cppcheck-analysis`-Job schlägt fehl und
     `cppcheck` generiert einen Bericht mit den gefundenen Fehlern.

3. **Statische Analyse Fehler**

   * **Beispiel**: Fügen Sie Code hinzu, der gegen Best Practices oder gängige
     Patterns verstößt, wie z.B. unnötige Kopien oder ungenutzte Variablen.
   * **Provozieren**: Schreiben Sie Code, der eine lokale Kopie einer großen
     Datenstruktur macht, ohne dass dies nötig ist.
   * **Erwartetes Ergebnis**: Der `static-analysis`-Job schlägt fehl und
     `clang-tidy` zeigt die problematischen Stellen im Code an.

4. **Build Fehler**

   * **Beispiel**: Fügen Sie Syntaxfehler oder fehlende Header-Dateien in den
     Code ein.
   * **Provozieren**: Schreiben Sie fehlerhaften C++ Code, z.B. vergessen Sie
     ein Semikolon oder inkludieren Sie eine nicht existierende Header-Datei.
   * **Erwartetes Ergebnis**: Der `build`-Job schlägt fehl und die Fehlermeldungen
     des Kompilers werden angezeigt.

5. **Test Fehler**

   * **Beispiel**: Ändern Sie den Code so, dass bestehende Tests fehlschlagen.
   * **Provozieren**: Ändern Sie eine Funktion so, dass sie nicht mehr die
     erwarteten Ergebnisse liefert.
   * **Erwartetes Ergebnis**: Der `test`-Job schlägt fehl und die Testergebnisse
     zeigen die fehlgeschlagenen Tests an.
