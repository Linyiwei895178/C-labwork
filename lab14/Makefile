# Makefile for lab12_1

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: lab12_1

lab12_1: lab12_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	cmd /c del /f /q lab12_1.exe 2>nul
	cmd /c del /f /q lab12_1 2>nul

.PHONY: all clean