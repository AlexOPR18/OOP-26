#include <iostream>
#include <cstdio>
#include <string>
#include "student.h"
#include "globals.h"

using namespace std;

int main()
{
    student s1;
    student s2;
    s1.setName("Alexandru");
    s2.setName("Stefan");
    s1.setNotaHist(6);
    s1.setNotaEng(10);
    s1.setNotaMate(9);
    s2.setNotaMate(6);
    cout<<"Studentul " <<s1.getName()<< " are la matematica nota: '" << s1.getNotaMate() << "'"<<endl;
    cout<<"Studentul " <<s2.getName()<< " are la matematica nota: '" << s2.getNotaMate() << "'" << endl;
    cout<<"Rezultatul compararii notelor la mate este: " << compNotaMate(s1, s2) << endl;
    cout<<"Studentul " <<s1.getName()<< " are media : '" << s1.getMedieNote() << "'"<<endl;
}