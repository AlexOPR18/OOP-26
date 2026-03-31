#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
    carCount = 0;
    circuitLength = 0;
    currentWeather = Weather::Sunny;
}

Circuit::~Circuit() {
    for (int i = 0; i<carCount; i++) {
        delete cars[i];
    }
}

void Circuit::SetLength(double length) {
    this->circuitLength = length;
}

void Circuit::SetWeather(Weather weather) {
    this->currentWeather = weather;
}

void Circuit::AddCar(Car* car) {
    if(carCount < 100) {
        cars[carCount++] = car;
    }
}

void Circuit::Race() {
    for(int i=0; i<carCount; i++) {
        Car* currentCar = cars[i];
        double speed = currentCar->GetAverageSpeed(currentWeather);
        double requiredFuel = (circuitLength/100)* currentCar->GetFuelConsumption();

        results[i].car = currentCar;

        if(requiredFuel<= currentCar->GetFuelCapacity()) {
            results[i].finished = true;
            results[i].time = circuitLength / speed;
        } else {
            results[i].finished = false;
            results[i].time = 0;
        }
    }
    for(int i = 0; i<carCount-1;i++) {
        for(int j = i+1; j<carCount; j++) {
            if((!results[i].finished && results[j].finished) ||
                (results[i].finished && results[j].finished && results[i].time > results[j].time)) {
                    RaceResult temp = results[i];
                    results[i] = results[j];
                    results[j] = temp;
                }
        }
    }
}

void Circuit::ShowFinalRanks() {
    std::cout<< "Ranks\n";
    int rank = 1;
    for (int i = 0; i<carCount;i++){
        if(results[i].finished) {
            std::cout <<rank++ << ". " <<results[i].car->GetName() <<" | Time: " << results[i].time <<" hours\n";
        }
    }
    std::cout << "\n";
}

void Circuit::ShowDNF() {
    std::cout << "DNF\n";
    for(int i=0; i<carCount;i++) {
        if(!results[i].finished) {
            std::cout << "- " << results[i].car->GetName() << "\n";
        }
    }
    std::cout<<"\n";
}