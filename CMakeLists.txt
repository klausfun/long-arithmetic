# Минимальная версия CMake-а
cmake_minimum_required(VERSION 3.16)

# Проект
project(LongArithmetic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление библиотеки
add_library(LongArithmetic SHARED
        hpp_files/LongNumber.hpp
        src/AuxiliaryMethods.cpp
        src/ComparisonOperations.cpp
        src/initFromString.cpp
        src/toString.cpp
        src/ArithmeticOperations.cpp
        src/LongNumber.cpp
        src/PrintLongNumber.cpp
        src/Tests.cpp
)

# Добавление исполняемого файла для вычисления числа Пи
add_executable(calculatePi calculatePi.cpp)

# Подключение библиотеки к файлу
target_link_libraries(calculatePi LongArithmetic)

# Добавление исполняемого файла для тестов
add_executable(runTests runTests.cpp)

# Подключение библиотеки к файлу с тестами
target_link_libraries(runTests LongArithmetic)

add_custom_target(pi COMMAND calculatePi)
add_custom_target(test COMMAND runTests)

# Проверяем, установлена ли переменная окружения PI_ITERATIONS
if(DEFINED ENV{PI_ITERATIONS})
    set(PI_ITERATIONS $ENV{PI_ITERATIONS})
else()
    set(PI_ITERATIONS 100) # По умолчанию используем 100 итераций
endif()

# Передаем количество итераций в качестве определения компилятора
target_compile_definitions(calculatePi PRIVATE PI_ITERATIONS=${PI_ITERATIONS})

add_custom_target(run COMMAND calculatePi ${PI_ITERATIONS})

## Минимальная версия CMake-а
#cmake_minimum_required(VERSION 3.16)
#
## Проект
#project(LongArithmetic LANGUAGES CXX)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
## Добавление библиотеки
#add_library(LongArithmetic SHARED
#        hpp_files/LongNumber.hpp
#        src/AuxiliaryMethods.cpp
#        src/ComparisonOperations.cpp
#        src/initFromString.cpp
#        src/toString.cpp
#        src/ArithmeticOperations.cpp
#        src/LongNumber.cpp
#        src/PrintLongNumber.cpp
#        src/Tests.cpp
#)
#
## Добавление исполняемого файла для вычисления числа Пи
#add_executable(calculatePi calculatePi.cpp)
#
## Подключение библиотеки к файлу
#target_link_libraries(calculatePi LongArithmetic)
#
## Добавление исполняемого файла для тестов
#add_executable(runTests runTests.cpp)
#
## Подключение библиотеки к файлу с тестами
#target_link_libraries(runTests LongArithmetic)
#
## Проверяем, установлена ли переменная окружения PI_ITERATIONS
#if(DEFINED ENV{PI_ITERATIONS})
#    set(PI_ITERATIONS $ENV{PI_ITERATIONS})
#else()
#    set(PI_ITERATIONS 100) # По умолчанию используем 100 итераций
#endif()
#
## Передаем количество итераций в качестве определения компилятора
#target_compile_definitions(calculatePi PRIVATE PI_ITERATIONS=${PI_ITERATIONS})
#
## Передаем значение PI_ITERATIONS как аргумент команде calculatePi
#add_custom_target(run COMMAND calculatePi)
