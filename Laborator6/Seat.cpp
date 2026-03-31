#include "Seat.h"

double Seat::GetFuelCapacity() const { return 45.0; }
double Seat::GetFuelConsumption() const { return 5.0; }
double Seat::GetAverageSpeed(Weather weather) const {
    if(weather == Weather::Rain) return 60.0;
    if(weather == Weather::Sunny) return 120.0;
    if(weather == Weather::Snow) return 40.0;
    return 70.0;
}
const char* Seat::GetName() const { return "Seat"; }