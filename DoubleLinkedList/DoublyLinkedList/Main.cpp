#include "DoublyLinkedList.h"
#include <iostream>
#include <list>
using namespace std;
int main () {
	
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList dll;
  cout << "list: " << dll << endl << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
 
  // add test for insertAfter
  cout << "\nInserting 200 after node 90" << endl;
  DListNode *temp = dll3.getFirst();
  while (temp->obj != 90)
          temp = temp->next;

  dll3.insertAfter(*temp, 200);
  cout << "list3: "<< dll3 << endl;

  // add test for insertBefore
  cout << "\nInserting 200 before node 100" << endl;
  DListNode *temp2 = dll3.getFirst();
  while (temp2->obj != 100)
          temp2 = temp2->next;

  dll3.insertBefore(*temp2, 200);
  cout << "list3: " << dll3 << endl;

  // add test for removeAfter
  cout << "\nRemove node after node 40" << endl;
  DListNode *temp3 = dll3.getFirst();
  while (temp3->obj != 40)
          temp3 = temp3->next;

  dll3.removeAfter(*temp3);
  cout << "list3: " << dll3 << endl;

  // add test for removeBefore
  cout << "\nRemove node before node 20" << endl;
  DListNode *temp4 = dll3.getFirst();
  while (temp4->obj != 20)
          temp4 = temp4->next;

  dll3.removeBefore(*temp4);
  cout << "list3: " << dll3 << endl;

  // add test for DoublyLinkedListLength
  cout << "\nTesting List Length for " << endl;
  cout << "list1: " << DoublyLinkedListLength(dll) << endl;
  cout << "list2: " <<DoublyLinkedListLength(dll2) << endl;
  cout << "list3: " <<DoublyLinkedListLength(dll3) << endl;
  
  return 0;
}
