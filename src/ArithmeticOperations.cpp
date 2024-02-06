#include "../hpp_files/LongNumber.hpp"

LongNumber LongNumber::operator*(const LongNumber& x) const
{
    size_t len = data.size() + x.data.size(); // максимальная длина нового числа не больше суммы длин перемножаемых чисел

    LongNumber res; // создадим объект для результата

    res.sign = sign * x.sign; // перемножаем знаки
    res.data = std::vector<int>(len, 0); // создаём вектор из нулей
    res.exponent = exponent + x.exponent; // складываем экспоненты

    // умножаем числа в столбик
    for (size_t i = 0; i < data.size(); i++)
        for (size_t j = 0; j < x.data.size(); j++)
            res.data[i + j + 1] += data[i] * x.data[j]; // прибавляем результат произведения цифр из i-го и j-го разрядов

    // в результате такого перемножения в ячейках могли получиться двузначные числа, поэтому нужно выполнить переносы
    for (size_t i = len - 1; i > 0; i--) {
        res.data[i - 1] += res.data[i] / 10; // добавляем к более старшему разряду десятки текущего разряда
        res.data[i] %= 10; // оставляем только единицы у текущего разряда
    }

    res.rounding();
    res.removeZeroes(); // удаляем нули, как в конструкторе из строки, если таковые имеются

    return res; // возвращаем результат умножения двух чисел
}

LongNumber LongNumber::operator-() const {
    LongNumber res; // создаём число
    res.sign = -sign; // меняем знак на противоположный
    res.exponent = exponent; // копируем экспоненту
    res.data = std::vector<int>(data); // копируем цифры

    return res; // возвращаем результат
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign == x.sign) { // если знаки одинаковые
        long exp1 = exponent; // запоминаем экспоненту первого
        long exp2 = x.exponent; // и второго чисел
        long exp = std::max(exp1, exp2); // находим максимальную экспоненту. К ней будем приводить оба числа

        // создаём вектора из векторов цифр наших чисел
        std::vector<int> d1(data);
        std::vector<int> d2(x.data);

        // выравниваем экспоненты
        while (exp1 != exp) {
            d1.insert(d1.begin(), 0); // добавляя нули в начало первого
            exp1++;
        }

        while (exp2 != exp) {
            d2.insert(d2.begin(), 0); // и в начало второго векторов
            exp2++;
        }

        size_t size = std::max(d1.size(), d2.size()); // определяем максимальный размер векторов

        // выравниваем размеры векторов, добавляя нули в конец каждого из них
        while (d1.size() != size)
            d1.push_back(0);

        while (d2.size() != size)
            d2.push_back(0);

        size_t len = 1 + size;

        LongNumber res; // создаём новое число

        res.sign = sign; // знак результата совпадает со знаком чисел
        res.data = std::vector<int>(len, 0); // создаём вектор из len нулей

        // заполняем каждую ячейку вектора суммой двух соответствующих цифр
        for (size_t i = 0; i < size; i++)
            res.data[i + 1] = d1[i] + d2[i];

        // проверяем переполнения
        for (size_t i = len - 1; i > 0; i--) {
            res.data[i - 1] += res.data[i] / 10; // прибавляем к более старшему разряду десятки текущего
            res.data[i] %= 10; // оставляем у текущего разряда только единицы
        }

        res.exponent = exp + 1; // восстанавливаем экспоненту
        res.rounding();
        res.removeZeroes(); // убираем нули
        return res; // возвращаем число
    }

    if (sign == -1)
        return x - (-(*this)); // если первое число отрицательное, то из второго вычитаем первое с обратным знаком

    return *this - (-x); // иначе из первого вычитаем второе с обратным знаком
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    if (sign == 1 && x.sign == 1) { // если оба числа положительны
        bool cmp = *this > x; // получаем флаг того, больше ли первое число

        long exp1 = cmp ? exponent : x.exponent; // сохраняем экспоненту большего числа
        long exp2 = cmp ? x.exponent : exponent; // сохраняем экспоненту меньшего числа
        long exp = std::max(exp1, exp2); // определяем максимальную экспоненту, чтобы к ней привести числа

        std::vector<int> d1(cmp ? data : x.data); // запоминаем вектор цифр большего числа
        std::vector<int> d2(cmp ? x.data : data); // запоминаем вектор цифр меньшего числа

        // выравниваем экспоненты как при сложении (добавляя нули вначале числа)
        while (exp1 != exp) {
            d1.insert(d1.begin(), 0);
            exp1++;
        }

        while (exp2 != exp) {
            d2.insert(d2.begin(), 0);
            exp2++;
        }

        size_t size = std::max(d1.size(), d2.size()); // определяем максимальный размер

        // добавляем нули в конец векторов цифр
        while (d1.size() != size)
            d1.push_back(0);

        while (d2.size() != size)
            d2.push_back(0);

        size_t len = 1 + size;

        LongNumber res; // создаём число для результата

        res.sign = cmp ? 1 : -1; // знак будет 1, если первое больше второго, и -1, если первое меньше второго
        res.data = std::vector<int>(len, 0); // создаём вектор из len нулей

        for (size_t i = 0; i < size; i++)
            res.data[i + 1] = d1[i] - d2[i]; // вычитаем соответствующие разряды

        // обрабатываем переполнения
        for (size_t i = len - 1; i > 0; i--) {
            if (res.data[i] < 0) { // если текущий разряд стал меньше нуля
                res.data[i] += 10; // занимаем у предыдущего, прибавляя 10 к текущему
                res.data[i - 1]--; // уменьшаем на 1 предыдущий разряд
            }
        }

        res.exponent = exp + 1; // восстанавливаем экспоненту
        res.rounding();
        res.removeZeroes(); // удаляем лишнии нули

        return res; // возвращаем результат
    }

    if (sign == -1 && x.sign == -1)
        return (-x) - (-(*this)); // если оба числа отрицательны, то из второго с обратным знаком вычитаем первое с обратным знаком

    return *this + (-x); // если знаки разные, прибавляем к первому отрицательное второе
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    LongNumber res = *this * x.inverse(); // выполняем умножение на обратный элемент

    // избавляемся от записи вида d...dd(9), которая эквивалентна d...dd+1
    size_t i = res.data.size() - 1 - std::max((long)0, exponent);
    size_t n = std::max((long)0, res.exponent);

    // если в указанном месте девятка, то ищем место, в котором девятки закончатся
    if (i > n && res.data[i] == 9) {
        while (i > n && res.data[i] == 9)
            i--;

        // если дошли до целой части
        if (res.data[i] == 9) {
            res.data.erase(res.data.begin() + n, res.data.end()); // то удаляем всю вещественную часть
            res = res + res.sign; // и прибавляем 1 (или -1 к отрицательному)
        }
        else {
            res.data.erase(res.data.begin() + i + 1, res.data.end()); // иначе обрезаем с найденного места
            res.data[i]++; // и увеличиваем на 1 текущий разряд
        }
    }
    res.rounding();
    res.removeZeroes();
    return res; // возвращаем результат деления
}






















//LongNumber LongNumber::operator-() const
//{
//    LongNumber res;
//    res.sign = -sign;
//    res.data = std::vector<int>(data);
//    res.exponent = exponent;
//
//    return res;
//}
//
//LongNumber LongNumber::operator*(const LongNumber& other) const
//{
//    size_t len1 = data.size(), len2 = other.data.size();
//    // максимальная длина нового числа не больше суммы длин перемножаемых чисел
//    size_t len = len1 + len2;
//
//    LongNumber res;
//
//    res.sign = sign * other.sign;
//    res.data = std::vector<int>(len, 0); // создаём вектор из нулей
//    res.exponent = exponent + other.exponent;
//
//    // умножаем числа в столбик
//    for (size_t i = 0; i < len1; i++)
//    {
//        for (size_t j = 0; j < len2; j++)
//        {
//            res.data[i + j + 1] += data[i] * other.data[j];
//        }
//    }
//
//    // в результате такого перемножения в ячейках могли получиться двузначные числа, поэтому нужно выполнить переносы
//    for (size_t i = len - 1; i > 0; i--)
//    {
//        res.data[i - 1] += res.data[i] / 10; // добавляем к более старшему разряду десятки текущего разряда
//        res.data[i] %= 10; // оставляем только единицы у текущего разряда
//    }
//
//    res.rounding();
//    res.removeZeroes();
//
//    return res;
//}
//
//LongNumber LongNumber::operator+(const LongNumber& other) const
//{
//    if (sign == other.sign)
//    {
//        size_t exp1 = exponent, exp2 = other.exponent;
//        size_t max_exp = std::max(exp1, exp2);
//
//        std::vector<int> data1(data);
//        std::vector<int> data2(other.data);
//
//        while (exp1++ != max_exp) data1.insert(data1.begin(), 0);
//        while (exp2++ != max_exp) data2.insert(data2.begin(), 0);
//
//        size_t max_size = std::max(data1.size(), data2.size());
//
//        while (data1.size() != max_size) data1.push_back(0);
//        while (data2.size() != max_size) data2.push_back(0);
//
//        max_size = std::max(data1.size(), data2.size());
//
//        LongNumber res;
//
//        res.sign = sign;
//        res.data = std::vector<int>(max_size + 1, 0);
//
//        int remains = 0;
//        size_t iter = max_size;
//        for (size_t i = max_size; i > 0; i--)
//        {
//            int sum = data1[i-1] + data2[i-1] + remains;
//            res.data[i] = sum % 10;
//            remains = sum / 10;
//            iter--;
//        }
//
//        if (remains > 0)
//        {
//            res.data[iter] = remains;
//        }
//
//        res.exponent = max_exp + 1;
//        res.removeZeroes();
//
//        return res;
//    }
//    else if (sign == -1)
//    {
//        return other - (-(*this));
//    }
//    else
//    {
//        return *this - (-other);
//    }
//}
//
//LongNumber LongNumber::operator-(const LongNumber& other) const
//{
//    if (sign == 1 && other.sign == 1)
//    {
//        bool comp_flag = *this > other;
////        std::cout << 1 << std::endl;
//        size_t exp1 = comp_flag ? exponent : other.exponent;
//        size_t exp2 = comp_flag ? other.exponent: exponent;
//        size_t max_exp = std::max(exp1, exp2);
//
//        std::vector<int> data1(comp_flag ? data : other.data);
//        std::vector<int> data2(comp_flag ? other.data : data);
//        std::cout << 1 << std::endl;
//
//        while (exp1++ <= max_exp) data1.insert(data1.begin(), 0);
//        std::cout << 1 << std::endl;
//        while (exp2++ <= max_exp) data2.insert(data2.begin(), 0);
//
//        while (data1.size() > LongNumber::precision_num + 5) data1.pop_back();
//        while (data2.size() > LongNumber::precision_num + 5) data2.pop_back();
//
//        size_t max_size = std::max(data1.size(), data2.size());
//
//        while (data1.size() != max_size) data1.push_back(0);
//        while (data2.size() != max_size) data2.push_back(0);
//
//        LongNumber res;
//
//        res.sign = comp_flag ? 1 : -1;
//        res.data = std::vector<int>(max_size + 1, 0);
//
//        int remains = 0;
//        size_t iter = max_size;
//        for (size_t i = max_size; i > 0; i--)
//        {
//            res.data[iter] = ((data1[i-1] - remains - data2[i-1]) + 10) % 10;
//            if ((data1[i-1] - remains - data2[i-1]) < 0) remains = 1;
//            else remains = 0;
//            iter--;
//        }
//
//        res.exponent = max_exp + 1;
//        res.removeZeroes();
//
//        return res;
//    }
//    if (sign == -1 && other.sign == -1)
//    {
//        return (-other) - (-(*this));
//    }
//    else
//    {
//        return *this + (-other);
//    }
//}
//
//LongNumber LongNumber::operator/(const LongNumber& other) const
//{
//    LongNumber res = *this * other.inverse();
//
//    size_t i = res.data.size() - 1 - std::max((long) 0, exponent);
//    size_t n = std::max((long) 0, res.exponent);
//
//    if (i > n && res.data[i] == 9)
//    {
//        while (i > n && res.data[i] == 9)
//            i--;
//
//        if (res.data[i] == 9)
//        {
//            res.data.erase(res.data.begin() + n, res.data.end());
//            res = res + res.sign;
//        }
//        else
//        {
//            res.data.erase(res.data.begin() + i + 1, res.data.end());
//            res.data[i]++;
//        }
//    }
//
//    res.rounding();
//    return res;
//}
