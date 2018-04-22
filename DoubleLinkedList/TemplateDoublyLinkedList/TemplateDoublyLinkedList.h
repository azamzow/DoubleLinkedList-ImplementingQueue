#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <stdexcept>

using namespace std;

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error
{
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};


template <class T> class DoublyLinkedList; 								// class declaration
// list node
template <class T> class DListNode {
// private:
//     T obj;
//     DListNode<T> *prev, *next;
//     friend class DoublyLinkedList<T>;
public:
    DListNode ( DListNode<T> *p = NULL, DListNode<T> *n = NULL)
        : prev(p), next(n) {}
        DListNode ( T e, DListNode<T> *p = NULL, DListNode<T> *n = NULL)
        : obj(e), prev(p), next(n) {}
	T getElem() const { return obj; }									//O(n)=1 
	DListNode<T> * getNext() const { return next; }						//O(n)=1
	DListNode<T> * getPrev() const { return prev; }						//O(n)=1
	T obj;
	DListNode<T> *prev, *next;
	friend class DoublyLinkedList<T>;
};

// doubly linked list
template <class T> class DoublyLinkedList {
private:
    DListNode<T> header, trailer;
public:
    DoublyLinkedList() : header(0), trailer(0) {						// constructor
    header.next = &trailer;
    trailer.prev = &header; 
}
	DoublyLinkedList(DoublyLinkedList<T>& dll); 						// copy constructor
	~DoublyLinkedList(); 												// destructor
	DoublyLinkedList& operator=(DoublyLinkedList<T>& dll);				 //copy assignment operator
	// return the pointer to the first node
	DListNode<T> *getFirst() const { return header.next; }				//O(n)=1
	// return the pointer to the trailer
	DListNode<T> *getAfterLast() { return &trailer;}					//O(n)=1
	// return if the list is empty
	bool isEmpty() const { return header.next == &trailer;}				//O(n)=1
	T first() const;													 // return the first object // O(n)=1
	T last() const;														 // return the last object // O(n)=1
	void insertFirst(T newobj); 										// insert to the first of the list
	T removeFirst(); 													// remove the first node
	void insertLast(T newobj); 											// insert to the last of the list
	T removeLast(); 													// remove the last node
	void insertAfter(DListNode<T> &p, T newobj);						// insterAfter a
	void insertBefore(DListNode<T> &p, T newobj); 						// insertBefore a node
	T removeAfter(DListNode<T> &p);										// removeAfter a node
	T removeBefore(DListNode<T> &p);									// removeBefore a node

DListNode<T>* insert(const T& obj);

};

template <class T> ostream& operator<<(ostream& out,DoublyLinkedList<T>& dll);		// output operator

template <class T> DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>& dll)	// copy constructor
{	
    header.next = &trailer;					// Initialize the list
    trailer.prev = &header;
    if (!dll.isEmpty())
    {
        DListNode<T>* node;
        node=dll.getFirst();
        while (node!=dll.getAfterLast())
        {
            insertLast(node->getElem());		//insert new element
            node=node->getNext();				//set node to next node
        }
    }
}

template <class T> DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>& dll)	// assignment operator
{

    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer)
    {
        prev_node = node;
        node = node->next;	//O(n)=n
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    
    if (!dll.isEmpty())								// Copy from dll
    {
        node=dll.getFirst();
        while (node!=dll.getAfterLast())	//O(n)=n
        {
            insertLast(node->getElem());			//insert new element
            node=node->getNext();					//set node to next node
        }
    } return *this;
    							//both parts of the constructor are O(n)=n the whole function is also O(n)=n
}

template <class T> void DoublyLinkedList<T>::insertFirst(T newobj)		// insert the object to the first of the linked list
{
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;												//O(n)=1
    header.next = newNode;
}

template <class T> void DoublyLinkedList<T>::insertLast(T newobj)		// insert the object to the last of the linked list
{
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;													//O(n)=1
    trailer.prev = newNode;
}

template <class T> T DoublyLinkedList<T>::removeFirst()					// remove the first object of the list
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;																	//O(n)=1
    delete node;
    return obj;
}

template <class T> T DoublyLinkedList<T>::removeLast()				// remove the last object of the list
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;																	//O(n)=1
    delete node;
    return obj;
}

template <class T> DoublyLinkedList<T>::~DoublyLinkedList()			// destructor
{
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer)
    {
        prev_node = node;
        node = node->next;															//O(n)=n
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

template <class T> T DoublyLinkedList<T>::first() const				// return the first object 
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");		//O(n)=1
    return header.next->obj;
}

template <class T> T DoublyLinkedList<T>::last() const				// return the last object
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");		//O(n)=1
    return trailer.prev->obj;
}

template <class T> void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)		// inster the new object after the node p
{
	DListNode<T> *newNode = new DListNode<T>(newobj, &p, p.next);					//allocate newNode
	p.next = newNode;																//O(n)=1
    if (newNode->next != NULL)														//Change previous of newNode's next node
      newNode->next->prev = newNode;
}

template <class T> void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)	// insert the new object before the node p
{																						//O(n)=1
    DListNode<T> *newNode = new DListNode<T>(newobj, p.prev, &p);				//allocate newNode
	p.prev = newNode;		
	if(newNode->prev != NULL){
		newNode->prev->next = newNode;
	}
}

template <class T> T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)			// remove the node after the node p
{																				//O(n)=1
    DListNode<T> *node = p.next;
	node->next->prev = node->prev;
	p.next = node -> next;
	T obj = node->obj;
	delete node;
	return obj;
}

template <class T> T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)			// remove the node before the node p
{																				//O(n)=1
    DListNode<T> *node = p.prev;
	node->prev->next = node->next;
	p.prev = node->prev;
	T obj = node->obj;
	delete node;
	return obj;
}

template <class T> int DoublyLinkedListLength(DoublyLinkedList<T>& dll)			// return the list length
{																				//O(n)=n
    DListNode<T> *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast())
    {
        count++;
        current = current->getNext(); 											//iterate
    }
    return count;
}

template <class T> DListNode<T>* DoublyLinkedList<T>::insert(const T& obj){ 	//runtime O(n)=n
    DListNode<T>* node= new DListNode<T>(obj);									//create node from object

    DListNode<T>* temp=getFirst();

    while(temp->getElem()<node->getElem()&&temp!=getAfterLast())				//find correct nodde
        temp=temp->getNext(); 													//insert before
    node->prev=temp->prev;
    node->next=temp;
    temp->prev->next=node;
    temp->prev=node;

    return node;
}

template <class T> ostream& operator<<(ostream& out, DoublyLinkedList<T>& dll)		// output operator
{
    DListNode<T>* temp=dll.getFirst();
    while (temp!=dll.getAfterLast()) 										//use address to compare pointers
    {   T object=temp->getElem();
        out<<object<< " ";													//O(n)=n
        temp=temp->getNext();
    }
    return out;
}
