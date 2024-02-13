#include "./hpp_files/LongNumber.hpp"
#include <iostream>

size_t LongNumber::precision_num;

void TestSum();
void TestSub();
void TestMul();
void TestDiv();
void TestRemoveZeros();
void TestInverse();
void TestEqual();
void TestNotEqual();
void TestCompLess();
void TestCompMore();
void TestCompMoreOrEq();
void TestCompLessOrEq();

int main()
{
    LongNumber::precision_num = 10;

    // Тесты:
    TestSum();
    TestSub();
    TestMul();
    TestDiv();
    TestRemoveZeros();
    TestInverse();
    TestEqual();
    TestNotEqual();
    TestCompLess();
    TestCompMore();
    TestCompMoreOrEq();
    TestCompLessOrEq();

    return 0;
}