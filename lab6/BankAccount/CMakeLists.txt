cmake_minimum_required(VERSION 4.1)
project(BankAccount)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankAccount main.cpp
        Date.cpp
        Date.h
        Account.cpp
        Account.h
)
