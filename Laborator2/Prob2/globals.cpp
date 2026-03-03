#include "globals.h"

int compNume(student s1, student s2)
{
    int rezultat = strcmp(s1.getName(), s2.getName());
    if(rezultat==0) {
        return 0;
    }else if(rezultat>0) {return 1;}
    else return -1;
}

int compNotaMate(student s1, student s2)
{
    if(s1.getNotaMate()==s2.getNotaMate()) {
        return 0;
    }else if(s1.getNotaMate()>s2.getNotaMate()) {return 1;}
    else return -1;
}

int compNotaEng(student s1, student s2)
{
    if(s1.getNotaEng()==s2.getNotaEng()) {
        return 0;
    }else if(s1.getNotaEng()>s2.getNotaEng()) {return 1;}
    else return -1;
}

int compNotaHist(student s1, student s2)
{
    if(s1.getNotaHist()==s2.getNotaHist()) {
        return 0;
    }else if(s1.getNotaHist()>s2.getNotaHist()) {return 1;}
    else return -1;
}

int compMedieNote(student s1, student s2)
{
    if(s1.getMedieNote()==s2.getMedieNote()) {
        return 0;
    }else if(s1.getMedieNote()>s2.getMedieNote()) {return 1;}
    else return -1;
}