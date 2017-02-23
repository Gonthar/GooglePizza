cmake_minimum_required(VERSION 3.6)
project(GooglePizza)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pizza.cpp pizza.h solutions.cpp solutions.h cover.cpp cover.h slice.cpp slice.h)
add_executable(GooglePizza ${SOURCE_FILES})