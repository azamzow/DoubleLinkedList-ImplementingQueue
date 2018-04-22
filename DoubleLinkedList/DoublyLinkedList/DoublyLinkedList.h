#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;
class DoublyLinkedList; // class declaration

// list node
class DListNode {
// private: int obj;
//   DListNode *prev, *next;
//   friend class DoublyLinkedList;
public:
  DListNode(int e=0, DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
  int getElem() const { return obj; }
  DListNode * getNext() const { return next; }
  DListNode * getPrev() const { return prev; }
  int obj;
  DListNode *prev, *next;
  friend class DoublyLinkedList;
};

// doubly linked list
class DoublyLinkedList {
private:
  DListNode header, trailer;		//header points to the front, trailer points to the end of the list
public:
  DoublyLinkedList() : header(0), trailer(0) 					// constructor
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList& dll); 				// copy constructor 
  ~DoublyLinkedList(); 											// destructor
  DoublyLinkedList& operator=(const DoublyLinkedList& dll); 	// assignment operator 
  // return the pointer to the first node
  DListNode *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode *getAfterLast() const { return &trailer; }
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  int first() const; 											// return the first object
  int last() const; 											// return the last object
  void insertFirst(int newobj);									// insert to the first of the list
  int removeFirst(); 											// remove the first node
  void insertLast(int newobj); 									// insert to the last of the list
  int removeLast(); 											// remove the last node
  void insertAfter(DListNode &p, int newobj);					// insterAfter a
  void insertBefore(DListNode &p, int newobj); 					// insertBefore a node
  int removeAfter(DListNode &p);								// removeAfter a node
  int removeBefore(DListNode &p);								// removeBefore a node
};

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll);
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll);				// gets length of list