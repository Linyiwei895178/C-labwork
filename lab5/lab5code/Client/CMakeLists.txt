cmake_minimum_required(VERSION 4.1)
project(lab5code)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5code main.cpp
        client.cpp
        client.h)
