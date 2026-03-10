#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include "Math.h"

using namespace std;

int main()
{
    Math calcule;
    int xi, yi, zi;
    double xd, yd, zd;
    const char a = 'a', b= 'b';
    int count;
    int numardenumere;
    
    cin>>xi>>yi>>zi>>xd>>yd>>zd;
    cout<<"Suma a doua numere intregi: "<<calcule.Add(xi, yi)<<endl;
    cout<<"Suma a trei numere intregi: "<<calcule.Add(xi,yi,zi)<<endl;
    cout<<"Suma a 2 numere fractionale: "<<calcule.Add(xd, yd)<<endl;
    cout<<"Suma a 3 numere fractionale: "<<calcule.Add(xd, yd, zd)<<endl;
    cout<<"Produsul a 2 numere intregi: "<<calcule.Mul(xi,yi)<<endl;
    cout<<"Produsul a 3 numere intregi: "<<calcule.Mul(xi,yi,zi)<<endl;
    cout<<"Produsul a 2 numere fractionale: "<<calcule.Mul(xd, yd)<<endl;
    cout<<"Produsul a 3 numere fractionale: "<<calcule.Mul(xd,yd,zd)<<endl;
    cout<<"Suma unui numar de numere intregi: "<<calcule.Add(5, 12,27,21,14,47)<<endl;
    cout<<"Suma a doua caractere: "<<calcule.Add(a,b);
}