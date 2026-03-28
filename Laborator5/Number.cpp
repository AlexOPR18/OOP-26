#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int Number::GetBase10Value() const {
    if(!value) return 0;
    return strtol(value, nullptr, base);
}

void Number::SetFromBase10(int val, int newBase) {
    base = newBase;
    if(val==0) {
        value = new char[2];
        strcpy(value, "0");
        return;
    }

    char buffer[100];
    int i=0;
    while(val>0) {
        int rem = val%newBase;
        if(rem<10) buffer[i++] = rem + '0';
        else buffer[i++] = rem - 10 + 'A';
        val /= newBase;
    }
    buffer[i] = '\0';

    int start=0, end=i-1;
    while(start<end) {
        char temp=buffer[start];
        buffer[start]=buffer[end];
        buffer[end]=temp;
        start++; end--;
    }
    value = new char[strlen(buffer)+1];
    strcpy(value, buffer);
}

Number::Number(const char* val, int base){
    this->base=base;
    this->value= new char[strlen(val)+1];
    strcpy(this->value, val);
}

Number::Number(int val){
    this->value = nullptr;
    SetFromBase10(val,10);
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) {
    base=other.base;
    value=new char[strlen(other.value)+1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) {
    base=other.base;
    value=other.value;
    other.value=nullptr;
    other.base=0;
}

Number& Number::operator=(const Number& other) {
    if(this!=&other) {
        delete[] value;
        base=other.base;
        value=new char[strlen(other.value)+1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) {
    if(this!=&other) {
        delete[] value;
        base=other.base;
        value=other.value;
        other.value=nullptr;
        other.base=0;
    }
    return *this;
}

Number& Number::operator=(int val) {
    delete[] value;
    SetFromBase10(val, this->base);
    return *this;
}

Number& Number::operator=(const char* val) {
    delete[] value;
    value=new char[strlen(val)+1];
    strcpy(value,val);
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int maxBase=(n1.base>n2.base) ? n1.base : n2.base;
    int sum=n1.GetBase10Value() + n2.GetBase10Value();
    Number result(0);
    result.SetFromBase10(sum, maxBase);
    return result;
}

Number operator-(const Number& n1, const Number& n2){
    int maxBase=(n1.base>n2.base) ? n1.base : n2.base;
    int diff=n1.GetBase10Value()-n2.GetBase10Value();
    Number result(0);
    result.SetFromBase10(diff, maxBase);
    return result;
}

Number& Number::operator+=(const Number& other) {
    int maxBase=(this->base > other.base) ? this->base : other.base;
    int sum = this->GetBase10Value() + other.GetBase10Value();
    delete[] this->value;
    this->SetFromBase10(sum, maxBase);
    return *this;
}

char Number::operator[](int index) const  {
    if(index>=0 && index<strlen(value)) return value[index];
    return '\0';
}

bool Number::operator>(const Number& other) const { return this->GetBase10Value()>other.GetBase10Value(); }
bool Number::operator<(const Number& other) const { return this->GetBase10Value()<other.GetBase10Value(); }
bool Number::operator>=(const Number& other) const { return this->GetBase10Value()>=other.GetBase10Value(); }
bool Number::operator<=(const Number& other) const { return this->GetBase10Value()<=other.GetBase10Value(); }
bool Number::operator==(const Number& other) const { return this->GetBase10Value()==other.GetBase10Value(); }
bool Number::operator!=(const Number& other) const { return this->GetBase10Value()!=other.GetBase10Value(); }

Number& Number::operator--() {
    if(value&&strlen(value)>1) {
        char* newVal = new char[strlen(value)];
        strcpy(newVal, value+1);
        delete[] value;
        value = newVal;
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    if(value&&strlen(value)>1) {
        value[strlen(value)-1]='\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) {
    int base10=GetBase10Value();
    delete[] value;
    SetFromBase10(base10, newBase);
}

void Number::Print() {
    if(value) cout<<value<<endl;
}

int Number::GetDigitsCount() {
    if(value) return strlen(value);
    return 0;
}

int Number::GetBase() { return base; }