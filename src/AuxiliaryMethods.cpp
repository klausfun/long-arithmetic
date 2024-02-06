#include "../hpp_files/LongNumber.hpp"

void LongNumber::removeZeroes()
{
    // Удаление лишних нулей справа
    while (!data.empty() && data.back() == 0)
    {
        data.pop_back();
    }

    // Удаление лишних нулей слева (после запятой)
    size_t leadingZeros = 0;
    size_t len = data.size();
    while (leadingZeros < len && data[leadingZeros] == 0)
    {
        leadingZeros++;
    }

    // Сдвигаем данные на leadingZeros позиций влево, чтобы убрать нули слева
    if (leadingZeros > 0)
    {
        data.erase(data.begin(), data.begin() + leadingZeros);
        exponent -= leadingZeros;  // Уменьшаем экспоненту на количество удаленных нулей слева
    }

    // Если в результате осталась всего одна нулевая цифра
    if (data.empty() || (data.size() == 1 && data[0] == 0))
    {
        exponent = 1;
        sign = 1;
    }

    // Если знак был минусом, а вся целая часть числа удалена
    if (sign == -1 && data.empty())
    {
        sign = 1; // Изменяем знак на положительный
    }
}

void LongNumber::rounding()
{
    // Вычисляем количество цифр после десятичной точки
    size_t decimal_digits = (exponent >= 0) ? exponent : -exponent;

    // Определяем длину вектора данных, необходимую для сохранения указанной точности
    size_t required_length = decimal_digits + LongNumber::precision_num + 10;

    // Обрезаем вектор данных, если его длина больше необходимой
    if (data.size() > required_length)
    {
        data.resize(required_length); // Обрезаем вектор данных до необходимой длины
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

LongNumber LongNumber::arctan(const LongNumber& x, int terms)
{
    LongNumber result("0");
    LongNumber power = x;
    bool subtractTerm = true;
    LongNumber x2 = x * x;
    LongNumber lastResult = result; // Переменная для хранения предыдущего результата
    size_t i = 1;

//    for (i = 1; i <= terms + 5; i += 2)
    while (true)
    {
        LongNumber term = power / i;
        i += 2;

        if (subtractTerm)
        {
            result = result + term;
        }
        else
        {
            result = result - term;
        }

        power = power * x2;
        subtractTerm = !subtractTerm;
//        std::cout << "result = " << result << " last = " << lastResult << std::endl;
        // Проверяем, изменилась ли точность результата
        if (result == lastResult) {
            break; // Если точность не изменилась, выходим из цикла
        } else {
            lastResult = result; // Обновляем значение предыдущего результата
        }
    }

    return result;
}




//void LongNumber::removeZeroes() {
//    size_t n = std::max((long) 1, exponent); // определяем, до какого момента нужно будет идти для удаления нулей справа
//
//    // пока справа нули
//    while (data.size() > n && data[data.size() - 1] == 0)
//        data.erase(data.end() - 1); // удаляем их
//
//    // пока число цифр больше одной и вектор начинается с нуля
//    while (data.size() > 1 && data[0] == 0) {
//        data.erase(data.begin()); // удаляем нули из начала вектора
//        exponent--; // и уменьшаем экспоненту
//    }
//
//    // если справа всё ещё остались нули
//    while (data.size() > 1 && data[data.size() - 1] == 0)
//        data.erase(data.end() - 1); // то удалим их
//
//    // если в результате осталась всего одна нулевая цифра, то превратим её в честный ноль
//    if (data.size() == 1 && data[0] == 0) {
//        exponent = 1;
//        sign = 1;
//    }
//}
