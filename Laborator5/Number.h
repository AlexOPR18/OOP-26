#pragma once

class Number
{
private:
    char* value;
    int base;

    int GetBase10Value() const;
    void SetFromBase10(int val, int newBase);

public:
    Number(const char* value, int base);
    Number(int value);
    ~Number();

    Number(const Number& other);
    Number(Number&& other);

    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int val);
    Number& operator=(const char* val);

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);

    char operator[](int index) const;

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};