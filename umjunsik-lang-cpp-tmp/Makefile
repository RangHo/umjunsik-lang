CXX = g++
CXXFLAGS = -Iinclude -std=c++20 -Wall

.PHONY: all clean

all: build/ummtmp

build/ummtmp: build/main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

build/main.o: src/main.cpp build
	$(CXX) $(CXXFLAGS) -c -o $@ $<

build:
	mkdir -p build

clean:
	rm -rf build
