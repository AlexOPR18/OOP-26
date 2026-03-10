#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int Math::Add(int x, int y)
{
    return x+y;
}

int Math::Add(int x, int y, int z)
{
    return x+y+z;
}

int Math::Add(double x, double y)
{
    return x+y;
}

int Math::Add(double x, double y, double z)
{
    return x+y+z;
}

int Math::Mul(int x, int y)
{
    return x*y;
}

int Math::Mul(int x, int y, int z)
{
    return x*y*z;
}

int Math::Mul(double x, double y)
{
    return x*y;
}

int Math::Mul(double x, double y, double z)
{
    return x*y*z;
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int rezultat = 0;
    int element = 0;
    while(count!=0)
    {
        element=va_arg(args,int);
        rezultat = rezultat + element;
        count--;
    }
    va_end(args);
    return rezultat;
}

char* Add(const char* a, const char* b)
{
    int nrA = atoi(a);
    int nrB = atoi(b);
    int suma;
    suma= nrA + nrB;
    char* rezult = new char[100];
    sprintf(rezult, "%d", suma);
    return rezult;
}