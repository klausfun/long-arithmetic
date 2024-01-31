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

