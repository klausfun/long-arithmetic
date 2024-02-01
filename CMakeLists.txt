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
)

# Добавление исполняемого файла
add_executable(pi src/main.cpp)

# Подключения библиотеки к файлу
target_link_libraries(pi LongArithmetic)

# Создание цели для запуска исполняемого файла
# Теперь можно писать make run для запуска проги
add_custom_target(run COMMAND pi)

## Создние исполняемого файла с тестами
#add_executable(tests tests.cpp)
#
## Подключения библиотеки к файлу с тестами
#target_link_libraries(tests real)
#
## Создание цели для запуска исполняемого файла с тестами
## Теперь можно писать make test для запуска тестов
#add_custom_target(test COMMAND tests)