cmake_minimum_required(VERSION 4.1)
project(Client1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Client1
        test.cpp
        client.cpp
        client.h)
