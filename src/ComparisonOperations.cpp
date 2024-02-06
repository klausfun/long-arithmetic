#include "../hpp_files/LongNumber.hpp"

LongNumber LongNumber::operator=(const LongNumber& other)
{
    if (this != &other) {
        sign = other.sign;
        data = other.data;
        exponent = other.exponent;
    }

    return *this;
}

bool LongNumber::operator>(const LongNumber& other) const
{
    if (sign != other.sign) return sign > other.sign;

    if (exponent != other.exponent)
    {
        // сравниваем экспоненты с учетом знака
        return (sign == 1) ? (exponent > other.exponent) : !(exponent > other.exponent);
    }

    size_t len1 = data.size(), len2 = other.data.size();

    if (len1 > LongNumber::precision_num + 5) len1 = LongNumber::precision_num + 5;
    if (len2 > LongNumber::precision_num + 5) len2 = LongNumber::precision_num + 5;

    size_t min_size = std::min(len1, len2);


    for (size_t i = 0; i < min_size; i++)
    {
        if (data[i] != other.data[i])
        {
            return (sign == 1) ? (data[i] > other.data[i]) : !(data[i] > other.data[i]);
        }
    }

    if (len1 == len2 || len1 < len2) return false;
    else return true;
}

bool LongNumber::operator<(const LongNumber& other) const
{
    return !(*this > other || *this == other);
}

bool LongNumber::operator==(const LongNumber& other) const
{
    return (!(*this > other) && !(other > *this));
}

bool LongNumber::operator!=(const LongNumber& other) const
{
    return !(*this == other);
}

bool LongNumber::operator<=(const LongNumber& other) const
{
    return (*this == other || *this < other);
}

bool LongNumber::operator>=(const LongNumber& other) const
{
    return (*this == other || *this > other);
}

bool LongNumber::operator>(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) > otherAsLongNumber;
}

bool LongNumber::operator<(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) < otherAsLongNumber;
}

bool LongNumber::operator==(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) == otherAsLongNumber;
}

bool LongNumber::operator!=(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) != otherAsLongNumber;
}

bool LongNumber::operator<=(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) <= otherAsLongNumber;
}

bool LongNumber::operator>=(const long double& other) const
{
    LongNumber otherAsLongNumber(other);
    return (*this) >= otherAsLongNumber;
}