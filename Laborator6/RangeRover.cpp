#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const { return 85.0; }
double RangeRover::GetFuelConsumption() const { return 13.0; }
double RangeRover::GetAverageSpeed(Weather weather) const {
    if(weather == Weather::Rain) return 120.0;
    if(weather == Weather::Sunny) return 180.0;
    if(weather == Weather::Snow) return 80.0;
    return 125.0;
}
const char* RangeRover::GetName() const { return "RangeRover"; }