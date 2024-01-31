#include "../hpp_files/LongNumber.hpp"
#include <iostream>

int main()
{
    LongNumber a("00398.07000");
    LongNumber b("010300.00200000");

    LongNumber c = b - a;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    return 0;
}
