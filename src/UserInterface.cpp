#include "UserInterface.hpp"
#include <iostream>
#include <string>
#include <vector>

void UserInterface::start() {
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            captureNewTrip();
            break;
        case 2:
            editTrip();
            break;
        case 3:
            deleteTrip();
            break;
        case 4:
            displayTrips();
            break;
        case 5:
            // Exit
            break;
        default:
            std::cout << "Ungültige Option, bitte nochmal versuchen." << std::endl;
        }
    }
}

void UserInterface::displayMenu() {
    std::cout << "\nFahrtenbuch Anwendung" << std::endl;
    std::cout << "1. Neue Fahrt hinzufügen" << std::endl;
    std::cout << "2. Fahrt bearbeiten" << std::endl;
    std::cout << "3. Fahrt löschen" << std::endl;
    std::cout << "4. Alle Fahrten anzeigen" << std::endl;
    std::cout << "5. Beenden" << std::endl;
    std::cout << "Bitte wählen Sie eine Option: ";
}

void UserInterface::captureNewTrip() {
    int id;
    std::string date, start, end, purpose;
    double startMileage, endMileage;

    std::cout << "Trip-ID eingeben: ";
    std::cin >> id;
    std::cin.ignore(); // Verbleibendes Newline-Zeichen im Input-Stream ignorieren

    std::cout << "Datum eingeben (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Startzeit eingeben (HH:MM): ";
    std::getline(std::cin, start);

    std::cout << "Endzeit eingeben (HH:MM): ";
    std::getline(std::cin, end);

    std::cout << "Startkilometerstand eingeben: ";
    std::cin >> startMileage;

    std::cout << "Endkilometerstand eingeben: ";
    std::cin >> endMileage;
    std::cin.ignore(); // Verbleibendes Newline-Zeichen im Input-Stream ignorieren

    std::cout << "Zweck der Fahrt eingeben: ";
    std::getline(std::cin, purpose);

    Trip newTrip(id, date, start, end, startMileage, endMileage, purpose);
    if (logbook.addTrip(newTrip)) {
        std::cout << "Fahrt erfolgreich hinzugefügt." << std::endl;
    } else {
        std::cout << "Fehler beim Hinzufügen der Fahrt." << std::endl;
    }
}

void UserInterface::editTrip() {
    // Bearbeiten eines Trips könnte ähnlich wie captureTrip()
    // implementiert werden
}

void UserInterface::deleteTrip() {
    int id;
    std::cout << "Geben Sie die ID der zu löschenden Fahrt ein: ";
    std::cin >> id;

    if (logbook.removeTrip(id)) {
        std::cout << "Fahrt erfolgreich gelöscht." << std::endl;
    } else {
        std::cout << "Fahrt mit der ID " << id << " wurde nicht gefunden." << std::endl;
    }
}

void UserInterface::displayTrips() {
    auto trips = logbook.getTripsList();
    for (const auto &trip : trips) {
        std::cout << "\n" << trip.getDetails() << "\n" << std::endl;
    }
}
