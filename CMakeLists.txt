cmake_minimum_required(VERSION 3.26)
project(FirstLibraryProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstLibraryProject src/main.cpp
        hpp_files/LongNumber.hpp
        src/LongNumber.cpp
        src/ArithmeticOperations.cpp
        src/toString.cpp
        src/PrintLongNumber.cpp
        src/AuxiliaryMethods.cpp
        src/initFromString.cpp
        src/ComparisonOperations.cpp)
