#pragma once
#include <cstring>

using namespace std;

class student{
    char nume[50];
    float notaMate;
    float notaEng;
    float notaHist;

public:
    const char* getName();
    int getNotaMate();
    int getNotaEng();
    int getNotaHist();

    
    void setName(const char* numeNou);
    void setNotaMate(int notaNoua);
    void setNotaEng(int notaNoua);
    void setNotaHist(int notaNoua);
    
    float getMedieNote();
};
