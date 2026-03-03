#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList lista1;
    lista1.Init();
    lista1.Add(21);
    lista1.Add(47);
    lista1.Add(54);
    lista1.Add(18);

    cout<<"Lista nesortata :";
    lista1.Print();
    lista1.Sort();
    cout<<"Lista sortata :";
    lista1.Print();

    return 0;
}