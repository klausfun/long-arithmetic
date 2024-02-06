#include "../hpp_files/LongNumber.hpp"
#include <iostream>
#include <chrono>

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



//LongNumber arctan(const LongNumber& x, int terms)
//{
//    LongNumber result("0");
//    LongNumber power = x;
//    bool subtractTerm = true;
//    LongNumber x2 = x * x;
//    for (int i = 1; i <= terms + 5; i += 2)
//    {
//        LongNumber term = power / i;
//
//        if (subtractTerm)
//        {
//            result = result - term;
//        }
//        else
//        {
//            result = result + term;
//        }
//
//        power = power * x2;
//        subtractTerm = !subtractTerm;
//    }
//
//    return result;
//}

LongNumber calculatePiMachin(int precision)
{
    LongNumber pi("0");
    LongNumber term1("1");
    term1 = term1.arctan(LongNumber("1") / 5, precision) * 4;

    LongNumber term2("1");
    term2 = term2.arctan(LongNumber("1") / 239, precision);

    pi = (term1 - term2) * 4;

    return pi;
}

int main()
{
    std::cout << "Please specify the precision of the decimal part of the number:" << std::endl;
    std::cin >> LongNumber::precision_num;

    // Тесты:
//    TestSum();
//    TestSub();
//    TestMul();
//    TestDiv();
//    TestRemoveZeros();
//    TestInverse();
//    TestEqual();
//    TestNotEqual();
//    TestCompLess();
//    TestCompMore();
//    TestCompMoreOrEq();
//    TestCompLessOrEq();

    // Расчет числа Пи

    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    LongNumber pi = calculatePiMachin(LongNumber::precision_num);

    std::cout << "pi = " << pi << std::endl;
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}