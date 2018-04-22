all: DoublyLinkedList.o main.o
	c++ -std=c++11 DoublyLinkedList.o main.o -o main
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	c++ -std=c++11 -c -g DoublyLinkedList.cpp
main.o: main.cpp DoublyLinkedList.h
	c++ -std=c++11 -c -g main.cpp
clean:
	rm *.o main