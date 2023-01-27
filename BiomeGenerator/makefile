all: BiomeGenerator1

run: BiomeGenerator1
	./BiomeGenerator1

BiomeGenerator1: BiomeGenerator1.o
	g++ -o BiomeGenerator1 BiomeGenerator1.o

BiomeGenerator1.o: BiomeGenerator1.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors BiomeGenerator1.cpp

clean: 
	rm -f *.o
	rm -f *~
	rm -f BiomeGenerator1
