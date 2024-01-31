#include "../hpp_files/LongNumber.hpp"

std::ostream& operator<<(std::ostream& os, const LongNumber& ln)
{
    os << ln.toString();

    return os;
}