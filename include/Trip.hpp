#pragma once

#include <string>

class Trip {
  private:
    int tripId;
    std::string date; // Vereinfachte Darstellung von Datum und Zeit als String
    std::string startTime;
    std::string endTime;
    double startMileage;
    double endMileage;
    std::string purpose;

  public:
    Trip(int id, std::string date, std::string start, std::string end,
         double startMile, double endMile, std::string purp);

    int getTripId() const;
    std::string getDate() const;
    std::string getStartTime() const;
    std::string getEndTime() const;
    double getStartMileage() const;
    double getEndMileage() const;
    std::string getPurpose() const;

    double calculateDistance() const;
    std::string getDetails() const;
};
