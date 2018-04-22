#include "DoublyLinkedList.h"
#include <stdexcept>
#include <list>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {						//exception
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)				// copy constructor
{
  // Initialize the list
	header.next = &trailer; trailer.prev = &header;
	if (!dll.isEmpty()){
		DListNode* node;
		node=dll.getFirst();
		while (node!=dll.getAfterLast()){
			insertLast(node->getElem());			//insert new element
			node=node->getNext();					//set node to next node
		}
	}
}

DoublyLinkedList::~DoublyLinkedList()				// destructor
{
	DListNode *prev_node, *node = header.next;		// make two pointers
	while (node != &trailer) {						// while the pointer is not the last node itterate through
		prev_node = node;
		node = node->next;
		delete prev_node;							// and delete
	}
	header.next = &trailer;
	trailer.prev = &header;
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)		// assignment operator
{
  // Delete the whole list
	DListNode *prev_node, *node = header.next;		// make two pointers
	while (node != &trailer) {						// while the pointer is not the last node itterate through
		prev_node = node;
		node = node->next;
		delete prev_node;							// and delete
	}
	header.next = &trailer;
	trailer.prev = &header;
	// Copy from dll
	if (!dll.isEmpty()){							// if list is not empty, copy all the elements over
		node=dll.getFirst();
		while (node!=dll.getAfterLast()){
			insertLast(node->getElem());			// insert new element
			node=node->getNext();					// set node to next node
		}
	}return *this;
}

void DoublyLinkedList::insertFirst(int newobj)		// insert the new object as the first one
{ 
    DListNode *newNode = new DListNode(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

void DoublyLinkedList::insertLast(int newobj)		// insert the new object as the last one
{
    DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
	trailer.prev-> next = newNode;
	trailer.prev = newNode;
}

int DoublyLinkedList::removeFirst()					// remove the first object from the list
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

int DoublyLinkedList::removeLast()					// remove the last object from the list
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

int DoublyLinkedList::first() const					// return the first object
{ 
	if (isEmpty())
	    throw EmptyDLinkedListException("Empty Doubly Linked List");
	return header.next->obj;
}

int DoublyLinkedList::last() const					// return the last object
{
	if (isEmpty())
	    throw EmptyDLinkedListException("Empty Doubly Linked List");
	return trailer.prev->obj;
}

void DoublyLinkedList::insertAfter(DListNode &p, int newobj)	//insert the new object after the node p
{
	DListNode *newNode = new DListNode(newobj, &p, p.next);		//allocate newNode
	p.next = newNode;
    if (newNode->next != NULL){									//Change previous of newNode's next node
		newNode->next->prev = newNode;
	}
}

void DoublyLinkedList::insertBefore(DListNode &p, int newobj)	// insert the new object before the node p
{
    DListNode *newNode = new DListNode(newobj, p.prev, &p);		//allocate newNode
	p.prev = newNode;
	if(newNode->prev != NULL){
		newNode->prev->next = newNode;							//Change next of newNode's previous node
	}
}

int DoublyLinkedList::removeAfter(DListNode &p)					// remove the node after the node p
{
    DListNode *node = p.next;
	node->next->prev = node->prev;
	p.next = node -> next;
	int obj = node->obj;
	delete node;
	return obj;
}

int DoublyLinkedList::removeBefore(DListNode &p)			// remove the node before the node p
{	
    DListNode *node = p.prev;
	node->prev->next = node->next;
	p.prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

int DoublyLinkedListLength(DoublyLinkedList& dll)			//return the list length
{
    DListNode *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()) {
      count++;
      current = current->getNext(); 						//iterate
    }
  return count;
}
	
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)	// output operator
{
    DListNode* temp=dll.getFirst();
    while (temp!=dll.getAfterLast()){						//use address to compare pointers
        out<<temp->getElem()<<" ";
        temp=temp->getNext();
	}
	return out;
}
