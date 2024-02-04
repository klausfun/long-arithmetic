#include "../hpp_files/LongNumber.hpp"

void LongNumber::removeZeroes() {
    // Удаление лишних нулей справа
    while (!data.empty() && data.back() == 0) {
        data.pop_back();
    }

    // Удаление лишних нулей слева (после запятой)
    size_t leadingZeros = 0;
    size_t len = data.size();
    while (leadingZeros < len && data[leadingZeros] == 0) {
        leadingZeros++;
    }

    // Сдвигаем данные на leadingZeros позиций влево, чтобы убрать нули слева
    if (leadingZeros > 0) {
        data.erase(data.begin(), data.begin() + leadingZeros);
        exponent -= leadingZeros;  // Уменьшаем экспоненту на количество удаленных нулей слева
    }

    // Если в результате осталась всего одна нулевая цифра
    if (data.empty() || (data.size() == 1 && data[0] == 0)) {
        exponent = 1;
        sign = 1;
    }

    // Если знак был минусом, а вся целая часть числа удалена
    if (sign == -1 && data.empty()) {
        sign = 1; // Изменяем знак на положительный
    }
}

LongNumber LongNumber::inverse() const
{
    if (*this == 0)
    {
        throw std::runtime_error("LongNumber::inverse() - division by zero!");
    }

    LongNumber x(*this);

    LongNumber res;
    res.exponent = 1;
    res.data = std::vector<int>();

    if (x.sign == -1)
    {
        x.sign = 1;
        res.sign = -1;
    }

    while (x < 1)
    {
        x.exponent++;
        res.exponent++;
    }

    LongNumber d("1");

    while (d < x)
        d.exponent++;

    res.exponent -= d.exponent - 1;

    size_t numbers = 0;
    size_t maxNumbers = approx_div + res.exponent;

    do
    {
        int div = 0;

        while (d >= x)
        {
            div++;
            d = d - x;
        }

        d.exponent++;
        d.removeZeroes();

        res.data.push_back(div);
        numbers++;
    } while (!(d == 0) && numbers < maxNumbers);

    return res;
}

//void LongNumber::RoundinUp()
//{
//    while (data.size() - exponent > LongNumber::precision_num)
//    {
//        data.pop_back();
//    }
//}