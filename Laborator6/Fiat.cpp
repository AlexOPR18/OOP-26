#include "Fiat.h"

double Fiat::GetFuelCapacity() const { return 40.0; }
double Fiat::GetFuelConsumption() const { return 5.0; }
double Fiat::GetAverageSpeed(Weather weather) const {
    if(weather == Weather::Rain) return 50.0;
    if(weather == Weather::Sunny) return 100.0;
    if(weather == Weather::Snow) return 30.0;
    return 90.0;
}
const char* Fiat::GetName() const { return "Fiat"; }