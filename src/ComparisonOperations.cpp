#include "../hpp_files/LongNumber.hpp"

bool LongNumber::operator>(const LongNumber& other) const
{
    if (sign != other.sign) return sign > other.sign;

    if (exponent != other.exponent)
    {
        // сравниваем экспоненты с учетом знака
        return (sign == 1) ? (exponent > other.exponent) : !(exponent > other.exponent);
    }


    size_t len1 = data.size(), len2 = other.data.size();
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