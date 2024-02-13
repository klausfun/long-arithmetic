#include "hpp_files/LongNumber.hpp"
#include <iostream>
#include <chrono>
#include <cstdlib>

size_t LongNumber::precision_num;

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
    // Расчет числа Пи

    // Получаем значение точности из переменной окружения PI_ITERATIONS
    const char* pi_iterations_str = std::getenv("PI_ITERATIONS");
    LongNumber::precision_num = (pi_iterations_str != nullptr) ? std::atoi(pi_iterations_str) : 100;

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