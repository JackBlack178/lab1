cmake_minimum_required(VERSION 3.17)
project(myLab C)

set(CMAKE_C_STANDARD 99)

add_executable(myLab main.c person.c person.h function.c function.h menu.c menu.h processValues.c processValues.h test.c test.h dynamicArray.c dynamicArray.h)