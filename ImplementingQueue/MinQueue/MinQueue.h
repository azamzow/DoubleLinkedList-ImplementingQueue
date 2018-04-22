#include <cstdlib>
#include <iostream>
#include <iostream>
#include <stdexcept>


using namespace std;

struct MyException: public exception			//throw exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};

struct Node {						
    int data;
    Node* next;
};
class MinQueue {					
    struct Node* head,* tail;		//head points to the front, trail points to the end of the list
public:
    MinQueue() { head = tail = NULL; }
    void enQueue(int x);
    void deQueue();
    int size();
    bool isEmpty();
	int min();
private:
	int size1 = 0;
};


void MinQueue::enQueue(int x) {					//inserts elements to the back
    Node* pointer = new Node;					//O(n)=1
    pointer -> data = x;
    pointer -> next = NULL;
    if(head == NULL) {
        head = pointer;
    }
    else
        tail -> next = pointer;
        tail = pointer;
		size1++;								//updates the size as we increament
        cout << "Element has been inserted in the queue!" << endl;
}

void MinQueue::deQueue() {						//removes from the back
    if(head == NULL){							//cant remove from an empty list
        cout << "Queue is empty!" << endl;		//O(n)=1
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
	size1--;									//updates the size as we decreament
}

int MinQueue::size() {							//Returns the size of the list
	return size1;								//O(n)=1
}

bool MinQueue::isEmpty(){						//checks to see if the list is empty
	return head->next = tail;					//O(n)=1
}

int MinQueue::min(){							// returns the minimum element of the whole list
	Node *min, *nextPoint;						//O(n)=n
	min = head;
	nextPoint = head;
	if (head != NULL){
		while (nextPoint != NULL){
			if (nextPoint->data < min->data){
				min = nextPoint;
			} else {
				nextPoint = nextPoint->next;
			}
		}
		return min->data;
	}
	else {									// list is empty
		throw MyException();
	}
}