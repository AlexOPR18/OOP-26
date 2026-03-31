#include "BMW.h"

double BMW::GetFuelCapacity() const { return 65.0; }
double BMW::GetFuelConsumption() const { return 10.0; }
double BMW::GetAverageSpeed(Weather weather) const {
    if(weather == Weather::Rain) return 100.0;
    if(weather == Weather::Sunny) return 160.0;
    if(weather == Weather::Snow) return 50.0;
    return 120.0;
}
const char* BMW::GetName() const { return "BMW"; }