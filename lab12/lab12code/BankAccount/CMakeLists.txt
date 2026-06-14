cmake_minimum_required(VERSION 3.10)

project(BankAccount)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bankaccount
                main.cpp
                Date.cpp
                Account.cpp
                SavingsAccount.cpp
                CreditAccount.cpp
)