# Fahrtenbuch

Das Fahrtenbuch ist ein C++-Projekt, das Benutzern ermöglicht, ihre Fahrten für berufliche oder private Zwecke zu erfassen und zu verwalten.

## Features

- Hinzufügen neuer Fahrten
- Bearbeiten bestehender Fahrten (noch nicht implementiert)
- Löschen von Fahrten
- Anzeigen aller gespeicherten Fahrten

## Projektstruktur

```text
Fahrtenbuch/
|-- bin/
|   |-- my_app (oder my_app.exe für Windows)
|   `-- test_app (oder test_app.exe für Windows)
|
|-- include/
|   |-- Logbook.hpp
|   |-- Trip.hpp
|   `-- UserInterface.hpp
|
|-- src/
|   |-- Logbook.cpp
|   |-- Trip.cpp
|   |-- UserInterface.cpp
|   `-- main.cpp
|
|-- test/
|   |-- logbook_test.cpp
|   `-- trip_test.cpp
|
|-- obj/
|
|-- Makefile
`-- README.md
```

## Übersetzung und Ausführung

### Manuelle Übersetzung der Anwendung

Für die manuelle Übersetzung verwenden Sie folgende Kommandos:

```text
g++ -std=c++17 -Wall -Iinclude -c src/Logbook.cpp -o obj/Logbook.o
g++ -std=c++17 -Wall -Iinclude -c src/Trip.cpp -o obj/Trip.o
g++ -std=c++17 -Wall -Iinclude -c src/UserInterface.cpp -o obj/UserInterface.o
g++ -std=c++17 -Wall -Iinclude -c src/main.cpp -o obj/main.o
g++ -std=c++17 -Wall -o bin/my_app obj/Logbook.o obj/Trip.o obj/UserInterface.o obj/main.o
```

### Manuelle Übersetzung der Tests

```text
g++ -std=c++17 -Wall -Iinclude -c test/logbook_test.cpp -o obj/logbook_test.o
g++ -std=c++17 -Wall -Iinclude -c test/trip_test.cpp -o obj/trip_test.o
g++ -std=c++17 -Wall -o bin/test_app obj/Logbook.o obj/Trip.o obj/UserInterface.o obj/logbook_test.o obj/trip_test.o 
```

### Automatische Übersetzung mit Makefile

```text
make all
make test
```

### Starten der Anwendung

```text
bin/my_app
```

### Starten der Testdurchläufe

```text
bin/test_app
```
