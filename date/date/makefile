main: main.o date.o
	g++ -o main -std=c++11 main.o date.o
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
date.o: date.h date.cpp
	g++ -c -std=c++11 date.h
	g++ -c -std=c++11 date.cpp
clean:
	-rm *.o
	-rm *.h.gch


