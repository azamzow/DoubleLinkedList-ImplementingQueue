#include "MinQueue.h"
#include <iostream>
#include <list>

using namespace std;

int main () {
	
	MinQueue que;								// create a list que
	cout << "\nInserting 6 elements: " << endl;							
	que.enQueue(5);								//inserts 5
	que.enQueue(9);								//inserts 9
	que.enQueue(8);								//inserts 8
	que.enQueue(7);								//inserts 7
	que.enQueue(11);							//inserts 11
	que.enQueue(10);							//inserts 10
	
	cout << "\nThe size of the list is: " << que.size() << endl;		// returns size of list que
	
	cout << "\n\nThe minimum elememt in the List is: " << que.min() << endl;		// gets the minimum element in the list
	
	cout << "\n\nRemoving the first element.. " << endl;				// remove from the frount
	que.deQueue();
	
	cout << "\n\nThe minimum elememt in the List is: " << que.min() << endl;		// gets the minimum element in the list
	
	cout << "\n\nRemoving the rest of the elements.. " << endl;			//// remove from the frount until empty
	que.deQueue();
	que.deQueue();
	que.deQueue();
	que.deQueue();
	que.deQueue();
	
	cout << "\nThe size of the list is: "<< que.size() << endl;			// returns size of list que
}