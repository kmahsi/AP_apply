all: main.o AdvancedCoffeMaker.o
	g++ -o a.out main.o AdvancedCoffeMaker.o
	rm *.o
	./a.out

main.o : AdvancedCoffeMaker.o
	g++ -c main.cpp

AdvancedCoffeMaker.o : AdvancedCoffeMaker.cpp
	g++ -c AdvancedCoffeMaker.cpp


clean:
	rm *.o