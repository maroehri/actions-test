#include "Logbook.hpp"

bool Logbook::addTrip(const Trip &trip) {
    trips.push_back(trip);
    return true; // Annahme, dass das Hinzufügen stets erfolgreich ist
}

bool Logbook::removeTrip(int tripId) {
    for (auto it = trips.begin(); it != trips.end(); ++it) {
        if (it->getTripId() == tripId) {
            trips.erase(it);
            return true;
        }
    }
    return false; // Trip mit dieser ID wurde nicht gefunden
}

bool Logbook::editTrip(int tripId, const Trip &newTrip) {
    for (auto &trip : trips) {
        if (trip.getTripId() == tripId) {
            trip = newTrip;
            return true;
        }
    }
    return false; // Trip mit dieser ID wurde nicht gefunden
}

std::vector<Trip> Logbook::getTripsList() const {
    return trips;
}
