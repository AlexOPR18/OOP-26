#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    cout << "Test 1: Functionare Normala" << endl;
    try {
        Array<int> arr(5);
        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Am adaugat 3 elemente. Elementul de pe pozitia 1 este: " << arr[1] << endl;
        cout << "\n Test 2: Provocam exceptia OutOfBounds" << endl;
        cout << "Incercam sa citim de la indexul 100..." << endl;
        cout << arr[100] << endl; 
        cout << "Acest mesaj nu va aparea." << endl; 

    } catch (exception& e) {
        cout << "EROARE PRINSA: " << e.what() << endl;
    }

    cout << "\n Test 3: Provocam exceptia de Capacitate Invalida" << endl;
    try {
        cout << "Incercam sa cream un Array cu capacitate negativa (-10)..." << endl;
        Array<int> badArray(-10); 

    } catch (exception& e) {
        cout << "EROARE PRINSA: " << e.what() << endl;
    }

    return 0;
}