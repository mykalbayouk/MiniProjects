all: KnockEmDown

run: KnockEmDown
	./KnockEmDown

KnockEmDown: KnockEmDown.o
	g++ -o KnockEmDown KnockEmDown.o

KnockEmDown.o: KnockEmDown.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors KnockEmDown.cpp

clean: 
	rm -f *.o
	rm -f *~
	rm -f KnockEmDown