#include <limits>
#include <string>
#include <cmath>
#include "../hpp_files/LongNumber.hpp"

LongNumber::LongNumber()
{
    sign = 1;
    exponent = 1;
    data = std::vector<int>(1, 0);
}

LongNumber::LongNumber(int sign, const std::vector<int>& data, long exponent):
            sign(sign), data(data), exponent(exponent)
{
}

LongNumber::LongNumber(long double value) {
    std::stringstream ss;
    ss << std::setprecision(15) << value;

    initFromString(ss.str());
    rounding();
    removeZeroes();
}

LongNumber::LongNumber(const std::string &stringValue)
{
    initFromString(stringValue);
    rounding();
    removeZeroes();
}

LongNumber operator""_ln(const char* str)
{
    LongNumber s(str);
    return s;
}
//LongNumber operator ""_ln(const char* string)
//{
//    LongNumber s(string);
//    return s;
//}