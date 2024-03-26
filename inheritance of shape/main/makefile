main: main.o shape.o square.o rectangle.o circle.o triangle.o
	g++ -o main -std=c++11 main.o shape.o square.o rectangle.o circle.o triangle.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

square.o: square.h square.cpp
	g++ -c -std=c++11 square.h
	g++ -c -std=c++11 square.cpp

rectangle.o: rectangle.h rectangle.cpp
	g++ -c -std=c++11 rectangle.h
	g++ -c -std=c++11 rectangle.cpp

circle.o: circle.h circle.cpp
	g++ -c -std=c++11 circle.h
	g++ -c -std=c++11 circle.cpp

triangle.o: triangle.h triangle.cpp
	g++ -c -std=c++11 triangle.h
	g++ -c -std=c++11 triangle.cpp

clean:
	-rm *.o
	-rm *.h.gch


