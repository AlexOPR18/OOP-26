#pragma once
#include <initializer_list>

class Sort
{
private:
    int* lista;
    int nrElemente;
public:
    Sort(int nrElemente, int min, int max);
    Sort(std::initializer_list<int> elemente);
    Sort(int* vector,int nrElemente);
    Sort(int count, ...);
    Sort(const char* text);
    ~Sort();
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};