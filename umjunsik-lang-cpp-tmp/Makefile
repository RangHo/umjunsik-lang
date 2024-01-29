UMJUNSIK_PROGRAM = "어떻게\n\n엄\n어엄\n어어엄\n어어어엄\n어어어어엄\n어어어어어엄\n어어어어어어엄\n어어어어어어어엄\n\n엄어..........\n동탄어?준..... .....\n\n어엄어어.......\n\n어어엄어어어..........\n\n어어어엄어어어어...\n\n어어어어엄어어어어어.\n\n엄어,\n준.............\n\n어엄어어..\n식어어ㅋ\n\n어어엄어어어.\n식어어어ㅋ\n어어엄어어어.......\n식어어어ㅋ\n식어어어ㅋ\n어어엄어어어...\n식어어어ㅋ\n\n어어어엄어어어어..............\n식어어어어ㅋ\n어어어엄어어어어,,,,,,,,,,,,\n식어어어어ㅋ\n\n어엄어어...............\n식어어ㅋ\n\n식어어어ㅋ\n어어엄어어어...\n식어어어ㅋ\n어어엄어어어,,,,,,\n식어어어ㅋ\n어어엄어어어,,,,,,,,\n식어어어ㅋ\n\n어어어엄어어어어.\n식어어어어ㅋ\n\n화이팅!.,\n\n이 사람이름이냐ㅋㅋ"

CXX = g++
CXXFLAGS = -Iinclude -std=c++20 -Wall -DUMJUNSIK_PROGRAM=\"$(UMJUNSIK_PROGRAM)\" $(CXXFLAGS_EXTRA)

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
