#include "../hpp_files/LongNumber.hpp"

void LongNumber::initFromString(const std::string& stringValue)
{
    size_t iter = 0;
    size_t len = stringValue.length();

    if (stringValue[0] == '-')
    {
        sign = -1;
        iter++;
    }
    else
    {
        sign = 1;
    }

    exponent = len - iter;

    for (size_t i = iter; i < len; i++)
    {
        if (stringValue[i] == '.')
        {
            if (sign == 1) exponent = i;
            else exponent = i - 1;
        }
        else
        {
            data.push_back(stringValue[i] - '0');
        }
    }
}
