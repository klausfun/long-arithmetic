#include "../hpp_files/LongNumber.hpp"
#include <cassert>
#include <chrono>

// ВСЕ ТЕСТЫ ВЫВОДЯТ НЕ БОЛЕЕ 10 ЗНАКОВ ПОСЛЕ ЗАПЯТОЙ!!!

void printTest(std::string name_test, std::vector<std::string> result)
{
    std::cout << name_test << std::endl << std::endl;

    int len = result.size();
    for (int i = 1; i <= len; i++)
    {
        std::cout << "Test " << i << std::endl;
        std::cout << result[i-1] << std::endl;
    }
}

void TestSum()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Ваш код, который вы хотите замерить
    // Тест 1: Сложение целых положительных чисел
    LongNumber num1_1("12345678901234567890");
    LongNumber num1_2("98765432109876543210");
    LongNumber result = num1_1 + num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "111111111011111111100" ? "OK" : "FAILED");

    // Тест 2: Сложение целых чисел с разными знаками
    LongNumber num2_1("-12345678901234567890");
    LongNumber num2_2("98765432109876543210");
    result = num2_1 + num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "86419753208641975320" ? "OK" : "FAILED");

    // Тест 3: Сложение целых отрицательных чисел
    LongNumber num3_1("-9283908029138419083089919209019039019309892");
    LongNumber num3_2("-931989831989389893018921189808921989281089");
    result = num3_1 + num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-10215897861127808976108840398827961008590981" ? "OK" : "FAILED");

    // Тест 4: Сложение положительных вещественных чисел
    LongNumber num4_1("123459839819.67291019308");
    LongNumber num4_2("98739031965.43201390190311");
    result = num4_1 + num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "222198871785.1049240949" ? "OK" : "FAILED");

    // Тест 5: Сложение вещественных чисел разных знаков
    LongNumber num5_1("-19901919483918.873238748027109487");
    LongNumber num5_2("82918942819384.8293289489328448291834");
    result = num5_1 + num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "63017023335465.9560902009" ? "OK" : "FAILED");

    // Тест 6: Сложение вещественных отрицательных чисел
    LongNumber num6_1("-191913452483918.32374802148");
    LongNumber num6_2("-30423042204021.210819813489128");
    result = num6_1 + num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-222336494687939.5345678349" ? "OK" : "FAILED");

    printTest("TestSum()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}
void TestSub()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Вычитание целых положительных чисел
    LongNumber num1_1("12345678901234567890");
    LongNumber num1_2("98765432109876543210");
    LongNumber result = num1_1 - num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-86419753208641975320" ? "OK" : "FAILED");

    // Тест 2: Вычитание целых чисел с разными знаками
    LongNumber num2_1("-12345678901234567890");
    LongNumber num2_2("98765432109876543210");
    result = num2_1 - num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-111111111011111111100" ? "OK" : "FAILED");

    // Тест 3: Вычитание целых отрицательных чисел
    LongNumber num3_1("-9283908029138419083089919209019039019309892");
    LongNumber num3_2("-931989831989389893018921189808921989281089");
    result = num3_1 - num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-8351918197149029190070998019210117030028803" ? "OK" : "FAILED");

    // Тест 4: Вычитание положительных вещественных чисел
    LongNumber num4_1("123459839819.67291019308");
    LongNumber num4_2("98739031965.43201390190311");
    result = num4_1 - num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "24720807854.2408962911" ? "OK" : "FAILED");

    // Тест 5: Вычитание вещественных чисел разных знаков
    LongNumber num5_1("-19901919483918.873238748027109487");
    LongNumber num5_2("82918942819384.8293289489328448291834");
    result = num5_1 - num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-102820862303303.7025676969" ? "OK" : "FAILED");

    // Тест 6: Вычитание вещественных отрицательных чисел
    LongNumber num6_1("-191913452483918.32374802148");
    LongNumber num6_2("-30423042204021.210819813489128");
    result = num6_1 - num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-161490410279897.1129282079" ? "OK" : "FAILED");

    printTest("TestSub()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestMul()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Умножение целых положительных чисел
    LongNumber num1_1("12345678901234567890");
    LongNumber num1_2("98765432109876543210");
    LongNumber result = num1_1 * num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "1219326311370217952237463801111263526900" ? "OK" : "FAILED");

    // Тест 2: Умножение целых чисел с разными знаками
    LongNumber num2_1("-12345678901234567890");
    LongNumber num2_2("98765432109876543210");
    result = num2_1 * num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-1219326311370217952237463801111263526900" ? "OK" : "FAILED");

    // Тест 3: Умножение целых отрицательных чисел
    LongNumber num3_1("-9283908029138419083089919209019039019309892");
    LongNumber num3_2("-931989831989389893018921189808921989281089");
    result = num3_1 * num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "8652507884281663048602912686212704012844699042345813515659943199014307902913986232388" ? "OK" : "FAILED");

    // Тест 4: Умножение положительных вещественных чисел
    LongNumber num4_1("12345983.67291019308");
    LongNumber num4_2("9873965.43201390190311");
    result = num4_1 * num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "121903816010523.2739811840" ? "OK" : "FAILED");

    // Тест 5: Умножение вещественных чисел разных знаков
    LongNumber num5_1("-1990191948.8732387480271487");
    LongNumber num5_2("8291894281.829328948934291834");
    result = num5_1 * num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-16502461240604776565.8504473004" ? "OK" : "FAILED");

    // Тест 6: Умножение вещественных отрицательных чисел
    LongNumber num6_1("-191913452483918.32374802148");
    LongNumber num6_2("-30423042204021.210819813489128");
    result = num6_1 * num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "5838591064437666436335413946.6269567564" ? "OK" : "FAILED");

    // Тест 7: Умножение на 0
    LongNumber num7_1("-191913452483918.32374802148");
    LongNumber num7_2("0");
    result = num7_1 * num7_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "0" ? "OK" : "FAILED");

    printTest("TestMul()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestDiv()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Деление целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("1234567890");
    LongNumber result = num1_1 / num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "66425829.1299211912" ? "OK" : "FAILED");

    // Тест 2: Деление целых чисел с разными знаками
    LongNumber num2_1("-1231234567890");
    LongNumber num2_2("11849138");
    result = num2_1 / num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-103909.2099264942" ? "OK" : "FAILED");

    // Тест 3: Деление целых отрицательных чисел
    LongNumber num3_1("-1888817348");
    LongNumber num3_2("2798001");
    result = num3_1 / num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-675.0595685991" ? "OK" : "FAILED");

    // Тест 4: Деление положительных вещественных чисел
    LongNumber num4_1("1234598399.67291019308");
    LongNumber num4_2("9873905.43201390190311");
    result = num4_1 / num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "125.0364820864" ? "OK" : "FAILED");

    // Тест 5: Деление вещественных чисел разных знаков
    LongNumber num5_1("-1990191918.87323809487");
    LongNumber num5_2("82918942819384.829328291834");
    result = num5_1 / num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-0.0000240016" ? "OK" : "FAILED");

    // Тест 6: Деление вещественных отрицательных чисел
    LongNumber num6_1("-99191348.323748");
    LongNumber num6_2("30423041.210819813489128");
    result = num6_1 / num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "-3.2604021286" ? "OK" : "FAILED");

    // Тест 7: Деление нуля на вещественное число
    LongNumber num7_1("0");
    LongNumber num7_2("30423041.210819813489128");
    result = num7_1 / num7_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result.toString() == "0" ? "OK" : "FAILED");

    printTest("TestDiv()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestRemoveZeros()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1
    LongNumber num1("0000000000427341.21240011142000000000000");
    num1.removeZeroes();
//    std::cout << "num1 = " << num1 << std::endl;
    res.push_back(num1.toString() == "427341.2124001114" ? "OK" : "FAILED");

    // Тест 2
    LongNumber num2("-00000000000.000021240011142000000000000");
    num2.removeZeroes();
//    std::cout << "num2 = " << num2 << std::endl;
    res.push_back(num2.toString() == "-0.0000212400" ? "OK" : "FAILED");

    // Тест 3
    LongNumber num3("00000000000.00000000000000000");
    num3.removeZeroes();
//    std::cout << "num3 = " << num3 << std::endl;
    res.push_back(num3.toString() == "0" ? "OK" : "FAILED");
    printTest("TestRemoveZeros()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestInverse()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1
    LongNumber num1("1");
    num1 = num1.inverse();
//    std::cout << "num1 = " << num1 << std::endl;
    res.push_back(num1.toString() == "1" ? "OK" : "FAILED");

    // Тест 2
    LongNumber num2("179110");
    num2 = num2.inverse();
//    std::cout << "num2 = " << num2 << std::endl;
    res.push_back(num2.toString() == "0.0000055831" ? "OK" : "FAILED");

    // Тест 3
    LongNumber num3("0.9810");
    num3 = num3.inverse();
//    std::cout << "num3 = " << num3 << std::endl;
    res.push_back(num3.toString() == "1.0193679918" ? "OK" : "FAILED");

    printTest("TestInverse()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestEqual()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Равенство целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007195710427341");
    bool result = num1_1 == num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 2: Равенство целых чисел разных знаков
    LongNumber num2_1("82007195710427341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 == num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 3: Равенство целых отрицательных чисел
    LongNumber num3_1("-82007195710427341");
    LongNumber num3_2("-82007195710427341");
    result = num3_1 == num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 4: Равенство вещественных положительных чисел
    LongNumber num4_1("820071957.10427341");
    LongNumber num4_2("820071957.10427341");
    result = num4_1 == num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 5: Равенство вещественных чисел разных знаков
    LongNumber num5_1("82007195.710427341");
    LongNumber num5_2("-82007195.710427341");
    result = num5_1 == num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 6: Равенство вещественных отрицательных чисел
    LongNumber num6_1("-82007195.710427341");
    LongNumber num6_2("-82007195.710427341");
    result = num6_1 == num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    printTest("TestEqual()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestNotEqual()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Не равенство целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007195710427341");
    bool result = num1_1 != num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    // Тест 2: Не равенство целых чисел разных знаков
    LongNumber num2_1("82007195710427341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 != num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 3: Не равенство целых отрицательных чисел
    LongNumber num3_1("-82007195710427341");
    LongNumber num3_2("-82007195710427341");
    result = num3_1 != num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    // Тест 4: Не равенство вещественных положительных чисел
    LongNumber num4_1("820071957.10427341");
    LongNumber num4_2("820071957.10427341");
    result = num4_1 != num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    // Тест 5: Не равенство вещественных чисел разных знаков
    LongNumber num5_1("82007195.710427341");
    LongNumber num5_2("-82007195.710427341");
    result = num5_1 != num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 6: Не равенство вещественных отрицательных чисел
    LongNumber num6_1("-82007195.710427341");
    LongNumber num6_2("-82007195.710427341");
    result = num6_1 != num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    printTest("TestNotEqual()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestCompLess()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Сравнение целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007127341");
    bool result = num1_1 < num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 2: Сравнение целых чисел разных знаков
    LongNumber num2_1("82007195717341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 < num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 3: Сравнение целых отрицательных чисел
    LongNumber num3_1("-82007195710427341259");
    LongNumber num3_2("-8200719571042734125");
    result = num3_1 < num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 4: Сравнение вещественных положительных чисел
    LongNumber num4_1("82007193657.10427341");
    LongNumber num4_2("820071957.10427341");
    result = num4_1 < num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 5: Сравнение вещественных чисел разных знаков
    LongNumber num5_1("82007195.710427341");
    LongNumber num5_2("-82007195.710427341");
    result = num5_1 < num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 6: Сравнение вещественных отрицательных чисел
    LongNumber num6_1("-82007195.910434");
    LongNumber num6_2("-82007195.7404341");
    result = num6_1 < num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    printTest("TestCompLess()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestCompMore()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Сравнение целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007127341");
    bool result = num1_1 > num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 2: Сравнение целых чисел разных знаков
    LongNumber num2_1("82007195717341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 > num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 3: Сравнение целых отрицательных чисел
    LongNumber num3_1("-82007195710427341259");
    LongNumber num3_2("-8200719571042734125");
    result = num3_1 > num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    // Тест 4: Сравнение вещественных положительных чисел
    LongNumber num4_1("82007193657.10427341");
    LongNumber num4_2("820071957.10427341");
    result = num4_1 > num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 5: Сравнение вещественных чисел разных знаков
    LongNumber num5_1("82007195.710427341");
    LongNumber num5_2("-82007195.710427341");
    result = num5_1 > num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != false ? "OK" : "FAILED");

    // Тест 6: Сравнение вещественных отрицательных чисел
    LongNumber num6_1("-82007195.910434");
    LongNumber num6_2("-82007195.7404341");
    result = num6_1 > num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    printTest("TestCompMore()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestCompLessOrEq()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Сравнение целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007127341");
    bool result = num1_1 <= num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 2: Сравнение целых чисел разных знаков
    LongNumber num2_1("82007195717341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 <= num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 3: Сравнение целых отрицательных чисел
    LongNumber num3_1("-82007195710427341259");
    LongNumber num3_2("-82007195710427341259");
    result = num3_1 <= num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 4: Сравнение вещественных положительных чисел
    LongNumber num4_1("82007193657.10427341");
    LongNumber num4_2("820071957143141.10427341");
    result = num4_1 <= num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 5: Сравнение вещественных чисел разных знаков
    LongNumber num5_1("82007195.710427341");
    LongNumber num5_2("-82007195.710427341");
    result = num5_1 <= num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 6: Сравнение вещественных отрицательных чисел
    LongNumber num6_1("-820071953.7404341");
    LongNumber num6_2("-820071953.7404341");
    result = num6_1 <= num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    printTest("TestCompLessOrEq()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}

void TestCompMoreOrEq()
{
    std::vector<std::string> res;
    // Получаем текущее время
    auto start_time = std::chrono::high_resolution_clock::now();

    // Тест 1: Сравнение целых положительных чисел
    LongNumber num1_1("82007195710427341");
    LongNumber num1_2("82007195710427341");
    bool result = num1_1 >= num1_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 2: Сравнение целых чисел разных знаков
    LongNumber num2_1("82007195717341");
    LongNumber num2_2("-82007195710427341");
    result = num2_1 >= num2_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 3: Сравнение целых отрицательных чисел
    LongNumber num3_1("-82007195710427341259");
    LongNumber num3_2("-8200719571042734125");
    result = num3_1 >= num3_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 4: Сравнение вещественных положительных чисел
    LongNumber num4_1("82007193657.10427341");
    LongNumber num4_2("82007193657.10427341");
    result = num4_1 >= num4_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == true ? "OK" : "FAILED");

    // Тест 5: Сравнение вещественных чисел разных знаков
    LongNumber num5_1("-82007195.710427341");
    LongNumber num5_2("82007195.710427341");
    result = num5_1 >= num5_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result == false ? "OK" : "FAILED");

    // Тест 6: Сравнение вещественных отрицательных чисел
    LongNumber num6_1("-82007195.910434");
    LongNumber num6_2("-82007195.7404341");
    result = num6_1 >= num6_2;
//    std::cout << "result = " << result << std::endl;
    res.push_back(result != true ? "OK" : "FAILED");

    printTest("TestCompMoreOrEq()", res);
    // Получаем текущее время после выполнения кода
    auto end_time = std::chrono::high_resolution_clock::now();

    // Вычисляем разницу между временем начала и конца
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Выводим результат
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}