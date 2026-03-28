#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cstring>

using namespace std;

Sort::Sort(int nrElemente, int min, int max){
    this->nrElemente = nrElemente;
    this->lista = new int[nrElemente];
    for(int i=0; i<nrElemente; i++)
    {
        this->lista[i]=min+rand()%(max - min +1);
    }
}

Sort::Sort(std::initializer_list<int> elemente){
    this->nrElemente = elemente.size();
    this->lista = new int[this->nrElemente];
    int i = 0;
    for(int x : elemente){
        this->lista[i]=x;
        i++;
    }
}

Sort::Sort(int* vector, int nrElemente){
    this->nrElemente = nrElemente;
    this->lista = new int[nrElemente];
    for(int i=0;i<nrElemente; i++){
        this->lista[i]=vector[i];
    }
}

Sort::Sort(int count, ...)
{
    this->nrElemente=count;
    this->lista = new int[count];

    va_list args;
    va_start(args, count);

    for(int i=0; i<count; i++){
        this->lista[i]=va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(const char* text) {
    int numere = 1;
    for(int i=0;text[i]!='\0';i++){
        if(text[i]==',') numere++;
    }
    this->nrElemente=numere;
    this->lista=new int[numere];
    char* textCopie = new char[strlen(text)+1];
    strcpy(textCopie, text);
    
    int i = 0;
    char* p = strtok(textCopie, ",");;
    while (p != NULL) {
        this->lista[i] = atoi(p);
        i++;
        p = strtok(NULL, ",");
    }
    delete[] textCopie;
}

Sort::~Sort() {
    delete[] this->lista;
}

void Sort::Print() {
    for (int i = 0; i < this->nrElemente; i++) {
        cout << this->lista[i] << " ";
    }
    cout << endl;
}

int Sort::GetElementsCount() {
    return this->nrElemente;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < this->nrElemente) {
        return this->lista[index];
    }
    return -1;
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < this->nrElemente - 1; i++) {
        for (int j = 0; j < this->nrElemente - i - 1; j++) {
            bool conditie = ascendent ? (this->lista[j] > this->lista[j + 1])
                                      : (this->lista[j] < this->lista[j + 1]);
            if (conditie) {
                int aux = this->lista[j];
                this->lista[j] = this->lista[j + 1];
                this->lista[j + 1] = aux;

            }
        }
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < this->nrElemente; i++) {
        int cheie = this->lista[i];
        int j = i - 1;
        bool conditie;
        while (j >= 0) {
            conditie = ascendent ? (this->lista[j] > cheie)
                                 : (this->lista[j] < cheie);
            if (!conditie) break;
            this->lista[j + 1] = this->lista[j];
            j--;
        }
        this->lista[j + 1] = cheie;
    }
}

int Partitie(int* arr, int low, int high, bool ascendent) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        bool conditie = ascendent ? (arr[j] < pivot) : (arr[j] > pivot);
        if (conditie) {
            i++;
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;

        }
    }
    int aux = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = aux;
    return (i + 1);
}

void QuickSortRec(int* arr, int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partitie(arr, low, high, ascendent);
        QuickSortRec(arr, low, pi - 1, ascendent);
        QuickSortRec(arr, pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent){
    QuickSortRec(this->lista, 0, this->nrElemente - 1,ascendent);
}