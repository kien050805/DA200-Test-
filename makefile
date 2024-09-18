all: mytests

mytests: mytests.o list
	g++ -o mytests mytests.o doublylinkedlist
	./mytests
	
mytests.o: mytests.cpp DoublyLinkedList.hpp
	g++ -c mytests.cpp 

list: DoublyLinkedList.cpp DoublyLinkedList.hpp
	g++ -c DoublyLinkedList.cpp -o doublylinkedlist

driver: mytests.cpp DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -o driver mytests.cpp
	./driver
 