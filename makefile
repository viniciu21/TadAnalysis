# makefile

all:
	mkdir -p bin
	g++ -Wall -c src/Node.cpp -o bin/Node.o
	g++ -Wall -c src/Doubly_Linked_List.cpp -o bin/Doubly_Linked_List.o
	g++ -Wall -c src/Queue.cpp -o bin/Queue.o

	g++ -Wall src/main.cpp bin/Doubly_Linked_List.o bin/Queue.o bin/Node.o -o bin/main
run:
	./bin/main