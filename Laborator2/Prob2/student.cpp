#include <iostream>
#include <cstdio>
#include <cstring>
#include "student.h"

using namespace std;

const char* student::getName()
{
    return nume; 
}

void student::setName(const char* numeNou)
{
    strcpy(this->nume, numeNou);
}

int student::getNotaMate()
{
    return notaMate;
}

void student::setNotaMate(int notaNoua)
{
    this->notaMate=notaNoua;
}

int student::getNotaEng()
{
    return notaEng;
}

void student::setNotaEng(int notaNoua)
{
    this->notaEng = notaNoua;
}

int student::getNotaHist()
{
    return notaHist;
}

void student::setNotaHist(int notaNoua)
{
    this->notaHist= notaNoua;
}

float student::getMedieNote()
{
    int suma = 0;
    float medie = 0;
    suma=suma+notaMate+notaEng+notaHist;
    medie = suma/3.0; 
    return medie;
}
