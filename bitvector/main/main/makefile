main: main.o bitvector.o
	g++ -o main -std=c++11 main.o bitvector.o
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
bitvector.o: bitvector.h bitvector.cpp
	g++ -c -std=c++11 bitvector.h
	g++ -c -std=c++11 bitvector.cpp
clean:
	-rm *.o
	-rm *.h.gch


