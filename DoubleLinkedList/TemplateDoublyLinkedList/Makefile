all: TemplateMain.o
	c++ -std=c++11 TemplateMain.o -o Main
TemplateMain.o: TemplateMain.cpp TemplateDoublyLinkedList.h
	c++ -std=c++11 -c -g TemplateMain.cpp
clean:
	rm *.o main
