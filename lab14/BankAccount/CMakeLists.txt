cmake_minimum_required(VERSION 3.10)
project(BankAccount LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(bank
    date.cpp
    account.cpp
    main.cpp
)