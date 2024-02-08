#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

class LongNumber;
LongNumber operator""_ln(const char* string);

class LongNumber
{
public:
    static size_t precision_num;

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

    bool operator>(const long double& other) const;
    bool operator<(const long double& other) const;
    bool operator==(const long double& other) const;
    bool operator!=(const long double& other) const;
    bool operator>=(const long double& other) const;
    bool operator<=(const long double& other) const;

    LongNumber& operator=(const LongNumber& other);

    // Арифметические операции
    LongNumber operator+(const LongNumber& other) const;
    LongNumber operator-(const LongNumber& other) const;
    LongNumber operator*(const LongNumber& other) const;
    LongNumber operator/(const LongNumber& other) const;

    LongNumber operator-() const; // унарный минус

    LongNumber arctan(const LongNumber &x, int terms);
    LongNumber inverse() const; // обратное число

    void rounding();
    void removeZeroes(); // удаляет лишние нули слева и справа
    void initFromString(const std::string& stringValue);

    std::string toString() const;  // метод для преобразования в строку
    friend std::ostream& operator<<(std::ostream& os, const LongNumber& value);

    friend LongNumber operator""_ln(const char* string);

private:
    const size_t approx_div = 1000;

    int sign;// Знак числа
    std::vector<int> data; // Вектор цифр (без точки)
    long exponent; // Экспонента
};
