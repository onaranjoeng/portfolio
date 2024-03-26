all: mydriver driver 

mydriver: mydriver.o
	g++ -o mydriver mydriver.o

driver: driver.o
	g++ -o driver driver.o

driver.o: driver.cpp tlist.h tnode.h
	g++ -c -std=c++11 driver.cpp

mydriver.o: mydriver.cpp tlist.h tnode.h
	g++ -c -std=c++11 mydriver.cpp
	g++ -c -std=c++11 tlist.h
	g++ -c -std=c++11 tnode.h

clean:
	-rm *.o
	-rm *.h.gch
	-rm *.hpp.gch
	-rm mydriver driver
