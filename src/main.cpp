#include "../hpp_files/LongNumber.hpp"
#include <iostream>
#include <chrono>
#include <cmath>

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

LongNumber arctanSeries(const LongNumber& x, int terms)
{
    LongNumber result("0");
    LongNumber power = x;
    bool subtractTerm = true;
    LongNumber x2 = x * x;
    for (int i = 1; i <= terms + 5; i += 2)
    {
        LongNumber term = power / i;

        if (subtractTerm)
            result = result - term;
        else
            result = result + term;

        power = power * x2;
        subtractTerm = !subtractTerm;
    }

    return result;
}

// Функция для вычисления числа π по формуле Мачина
LongNumber calculatePiMachinFormula(int terms)
{
    LongNumber pi_over_4 = LongNumber("4") * arctanSeries(LongNumber("1") / LongNumber("5"), terms) -
                           arctanSeries(LongNumber("1") / LongNumber("239"), terms);
    return pi_over_4 * LongNumber("4");
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
//    std::cout <<
    // Расчет числа Пи

    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();
    LongNumber c("1");
    LongNumber pi = arctanSeries(c, 5);
//    LongNumber pi = calculatePiMachinFormula(LongNumber::precision_num);
    std::cout << "pi = " << pi << std::endl;
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}