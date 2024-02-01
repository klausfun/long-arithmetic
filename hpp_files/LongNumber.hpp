#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

class LongNumber
{
public:
    LongNumber();  // Конструктор по умолчанию
    LongNumber(int sign, const std::vector<int>& digits, long exponent);
    LongNumber(const std::string &stringValue); // Конструктор из строки
    LongNumber(long double value); // Конструктор из 'короткого' числа

    // Операции сравнения
    bool operator>(const LongNumber& other) const;
    bool operator<(const LongNumber& other) const;
    bool operator==(const LongNumber& other) const;
    bool operator!=(const LongNumber& other) const;
    bool operator>=(const LongNumber& other) const;
    bool operator<=(const LongNumber& other) const;

    // Арифметические операции
    LongNumber operator+(const LongNumber& other) const;
    LongNumber operator-(const LongNumber& other) const;
    LongNumber operator*(const LongNumber& other) const;
    LongNumber operator/(const LongNumber& other) const;

    LongNumber operator-() const; // унарный минус


    std::string toString() const;  // Метод для преобразования в строку
    friend std::ostream& operator<<(std::ostream& os, const LongNumber& value);

    void initFromString(const std::string& stringValue);
    void removeZeroes();

    friend LongNumber operator "" _ln(const char* string);


private:
    int sign;// Знак числа
    std::vector<int> data; // Вектор цифр (без точки)
    long exponent; // Экспонента

};

