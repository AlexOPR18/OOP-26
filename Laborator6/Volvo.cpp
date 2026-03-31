#include "Volvo.h"
double Volvo::GetFuelCapacity() const { return 70.0; }
double Volvo::GetFuelConsumption() const { return 8.5; }
double Volvo::GetAverageSpeed(Weather weather) const {
    if(weather == Weather::Rain) return 90.0;
    if(weather == Weather::Sunny) return 120.0;
    if(weather == Weather::Snow) return 60.0;
    return 100.0;
}
const char* Volvo::GetName() const { return "Volvo"; }