
compile = g++ -std=c++11

all: main.o advancedCoffeMaker.o graph.o node.o
	$(compile) -o a.out main.o advancedCoffeMaker.o graph.o node.o
	rm *.o
	./a.out

main.o : advancedCoffeMaker.h main.cpp graph.h node.h
	$(compile) -c main.cpp

advancedCoffeMaker.o : advancedCoffeMaker.cpp graph.h node.h
	$(compile) -c advancedCoffeMaker.cpp

graph.o : graph.cpp node.h
	$(compile) -c graph.cpp

node.o : node.cpp node.h
	$(compile) -c node.cpp


clean:
	rm *.o