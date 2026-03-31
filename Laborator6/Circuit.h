#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    Car* cars[100];
    int carCount;
    double circuitLength;
    Weather currentWeather;

    struct RaceResult {
        Car* car;
        double time;
        bool finished;
    };
    RaceResult results[100];

public:
    Circuit();
    ~Circuit();

    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowDNF();
};