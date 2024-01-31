#include "../hpp_files/LongNumber.hpp"

std::string LongNumber::toString() const
{
    std::stringstream ss;
    if (sign == -1) ss << '-';

    if (exponent > 0)
    {
        size_t iter = 0;
        size_t exp = exponent;
        size_t len = data.size();

        while (iter < exp && iter < len)
        {
            ss << data[iter];
            iter++;
        }

        while (iter < exp)
        {
            ss << "0";
            iter++;
        }

        if (iter < len)
        {
            ss << ".";
            while (iter < len)
                ss << data[iter++];
        }
    }
    else
    {
        size_t len = data.size();

        ss << "0.";

        for (size_t i = 0; i < -exponent; i++)
        {
            ss << "0";
        }

        for (size_t i = 0; i < len; i++)
        {
            ss << data[i];
        }
    }

    return ss.str();
}
