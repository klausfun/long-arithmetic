#include "../hpp_files/LongNumber.hpp"

LongNumber LongNumber::operator-() const
{
    LongNumber res;
    res.sign = -sign;
    res.data = std::vector<int>(data);
    res.exponent = exponent;

    return res;
}

LongNumber LongNumber::operator*(const LongNumber& other) const
{
    size_t len1 = data.size(), len2 = other.data.size();
    // максимальная длина нового числа не больше суммы длин перемножаемых чисел
    size_t len = len1 + len2;

    LongNumber res;

    res.sign = sign * other.sign;
    res.data = std::vector<int>(len, 0); // создаём вектор из нулей
    res.exponent = exponent + other.exponent;

    // умножаем числа в столбик
    for (size_t i = 0; i < len1; i++)
    {
        for (size_t j = 0; j < len2; j++)
        {
            res.data[i + j + 1] += data[i] * other.data[j];
        }
    }

    // в результате такого перемножения в ячейках могли получиться двузначные числа, поэтому нужно выполнить переносы
    for (size_t i = len - 1; i > 0; i--)
    {
        res.data[i - 1] += res.data[i] / 10; // добавляем к более старшему разряду десятки текущего разряда
        res.data[i] %= 10; // оставляем только единицы у текущего разряда
    }

    res.removeZeroes();

    return res;
}

LongNumber LongNumber::operator+(const LongNumber& other) const
{
    if (sign == other.sign)
    {
        size_t exp1 = exponent, exp2 = other.exponent;
        size_t max_exp = std::max(exp1, exp2);

        std::vector<int> data1(data);
        std::vector<int> data2(other.data);

        while (exp1++ != max_exp) data1.insert(data1.begin(), 0);
        while (exp2++ != max_exp) data2.insert(data2.begin(), 0);

        size_t max_size = std::max(data1.size(), data2.size());

        while (data1.size() != max_size) data1.push_back(0);
        while (data2.size() != max_size) data2.push_back(0);

        max_size = std::max(data1.size(), data2.size());

        LongNumber res;

        res.sign = sign;
        res.data = std::vector<int>(max_size + 1, 0);

        int remains = 0;
        size_t iter = max_size;
        for (size_t i = max_size; i > 0; i--)
        {
            int sum = data1[i-1] + data2[i-1] + remains;
            res.data[i] = sum % 10;
            remains = sum / 10;
            iter--;
        }

        if (remains > 0)
        {
            res.data[iter] = remains;
        }

        res.exponent = max_exp + 1;
        res.removeZeroes();

        return res;
    }
    else if (sign == -1)
    {
        return other - (-(*this));
    }
    else
    {
        return *this - (-other);
    }
}

LongNumber LongNumber::operator-(const LongNumber& other) const
{
    if (sign == 1 && other.sign == 1)
    {
        bool comp_flag = *this > other;
        size_t exp1 = comp_flag ? exponent : other.exponent;
        size_t exp2 = comp_flag ? other.exponent : exponent;
        size_t max_exp = std::max(exp1, exp2);

        std::vector<int> data1(comp_flag ? data : other.data);
        std::vector<int> data2(comp_flag ? other.data : data);

        while (exp1++ != max_exp) data1.insert(data1.begin(), 0);
        while (exp2++ != max_exp) data2.insert(data2.begin(), 0);

        size_t max_size = std::max(data1.size(), data2.size());

        while (data1.size() != max_size) data1.push_back(0);
        while (data2.size() != max_size) data2.push_back(0);

        max_size = std::max(data1.size(), data2.size());

        LongNumber res;

        res.sign = comp_flag ? 1 : -1;
        res.data = std::vector<int>(max_size + 1, 0);

        int remains = 0;
        size_t iter = max_size;
        for (size_t i = max_size; i > 0; i--)
        {
            res.data[iter] = ((data1[i-1] - remains - data2[i-1]) + 10) % 10;
            if ((data1[i-1] - remains - data2[i-1]) < 0) remains = 1;
            else remains = 0;
            iter--;
        }

        res.exponent = max_exp + 1;
        res.removeZeroes();

        return res;
    }
    if (sign == -1 && other.sign == -1)
    {
        return (-other) - (-(*this));
    }
    else
    {
        return *this + (-other);
    }
}

LongNumber LongNumber::operator/(const LongNumber& other) const
{
    LongNumber res = *this * other.inverse();

    size_t i = res.data.size() - 1 - std::max((long) 0, exponent);
    size_t n = std::max((long) 0, res.exponent);

    if (i > n && res.data[i] == 9)
    {
        while (i > n && res.data[i] == 9)
            i--;

        if (res.data[i] == 9)
        {
            res.data.erase(res.data.begin() + n, res.data.end());
            res = res + res.sign;
        }
        else
        {
            res.data.erase(res.data.begin() + i + 1, res.data.end());
            res.data[i]++;
        }
    }

    return res;
}

//LongNumber LongNumber::operator/(const LongNumber& other) const
//{
//    if (other == 0)
//    {
//        std::cout << "Деление на 0!" << std::endl;
//        return 0;
//    }
//
//    LongNumber numerator(*this);
//    LongNumber denominator(other);
//    LongNumber result;
//
//    // Устанавливаем знак результата
//    result.sign = sign * other.sign;
//
//    // Избавляемся от лишних нулей в числителе
//    while (numerator != 0 && numerator.data.back() == 0)
//        numerator.data.pop_back();
//
//    // Избавляемся от лишних нулей в знаменателе
//    while (numerator != 0 && denominator.data.back() == 0)
//        denominator.data.pop_back();
//
//    // Если числитель меньше знаменателя, результат равен 0
//    if (numerator < denominator)
//        return 0;
//
//    // Вычисляем разницу в экспонентах числителя и знаменателя
//    result.exponent = numerator.exponent - denominator.exponent;
//
//    // Выравниваем экспоненты, добавляя нули к числителю
//    while (numerator.exponent > denominator.exponent)
//    {
//        denominator.data.insert(denominator.data.begin(), 0);
//        denominator.exponent++;
//    }
//
//    size_t quotientSize = numerator.data.size() - denominator.data.size() + 1;
//    result.data.resize(quotientSize, 0);
//
//    LongNumber tempDenominator;
//
//    for (size_t i = 0; i < quotientSize; ++i)
//    {
//        int quotientDigit = 0;
//
//        while (numerator >= (tempDenominator + 1) * denominator)
//        {
//            tempDenominator = tempDenominator + 1;
//
//            // Дополнительная проверка на выход за пределы массива
//            if (tempDenominator.data.size() > quotientSize)
//            {
//                std::cerr << "Error: tempDenominator.data size exceeds quotientSize." << std::endl;
//                std::abort();
//            }
//
//            quotientDigit++;
//
//            // Дополнительная проверка на возможность бесконечного цикла
//            if (quotientDigit > 1000000)
//            {
//                std::cerr << "Error: Potential infinite loop detected." << std::endl;
//                std::abort();
//            }
//        }
//
//        result.data[i] = quotientDigit;
//        numerator = numerator - tempDenominator * denominator;
//
//        std::cout << "Debug Info: numerator = " << numerator << ", denominator = " << denominator << std::endl;
//
//        tempDenominator.data.clear();
//        tempDenominator.exponent = 0;
//    }
//
//    result.removeZeroes();
//
//    return result;
//}
