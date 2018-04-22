#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "\nCreate a new list" << endl;
  DoublyLinkedList<string> dll;
  cout << "list: " << dll << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "\nInsert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl;
  
  // Copy to a new list
  cout << "\nCopy to a new list" << endl;
  DoublyLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl;
  
  // Assign to another new list
  cout << "\nAssign to another new list" << endl;
  DoublyLinkedList<string> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl;
  
  // Delete the last 10 nodes
  cout << "\nDelete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl;
  
  // Delete the first 10 nodes
  cout << "\nDelete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl;
  
  // Check the other two lists
  cout << "\nMake sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
 
  // add test for insertAfter
  cout << "\nInserting 200 after node 90" << endl;
 // DListNode<int> *temp = dll3.getFirst();
  auto temp = dll3.getFirst();
  while (temp->obj != "90")
          temp = temp->next;

  dll3.insertAfter(*temp, "200");
  cout << "list3: "<< dll3 << endl;

  // add test for insertBefore
  cout << "\nInserting 200 before node 100" << endl;
  //DListNode<T> *temp2 = dll3.getFirst();
  auto temp2 = dll3.getFirst();
  while (temp2->obj != "100")
          temp2 = temp2->next;

  dll3.insertBefore(*temp2, "200");
  cout << "list3: " << dll3 << endl;

  // add test for removeAfter
  cout << "\nRemove node after node 40" << endl;
  //DListNode<T> *temp3 = dll3.getFirst();
  auto temp3 = dll3.getFirst();
  while (temp3->obj != "40")
          temp3 = temp3->next;

  dll3.removeAfter(*temp3);
  cout << "list3: " << dll3 << endl;

  // add test for removeBefore
  cout << "\nRemove node before node 20" << endl;
  //DListNode<T> *temp4 = dll3.getFirst();
  auto temp4 = dll3.getFirst();
  while (temp4->obj != "20")
          temp4 = temp4->next;

  dll3.removeBefore(*temp4);
  cout << "list3: " << dll3 << endl;

  // add test for DoublyLinkedListLength
  cout << "\nTesting List Length for " << endl;
  cout << "list1: " << DoublyLinkedListLength(dll) << endl;
  cout << "list2: " << DoublyLinkedListLength(dll2) << endl;
  cout << "list3: " << DoublyLinkedListLength(dll3) << endl;
  
  /************************************** STRING *************************************/
  cout << "\n******************** Using STRING in lists: *********************" << endl;
  
  cout << "\nCreate a new list" << endl;
  DoublyLinkedList<string> dll4;
  cout << "list: " << dll4 << endl << endl;

  // Insert 3 nodes at back with value A, B, C
  cout << "\nInsert 3 nodes at back with value A, B, C " << endl;
  dll4.insertLast("A");
  dll4.insertLast("B");
  dll4.insertLast("C");
  cout << "list: " << dll4 << endl;

  // Insert 3 nodes at front with value A, B, C
  cout << "\nInsert 3 nodes at front with value A, B, C" << endl;
  dll4.insertFirst("A");
  dll4.insertFirst("B");
  dll4.insertFirst("C");
  cout << "list: " << dll4 << endl;

  // Copy to a new list
  cout << "\nCopy to a new list" << endl;
  DoublyLinkedList<string> dll5(dll4);
  cout << "list2: " << dll5 << endl;

  // Assign to another new list
  cout << "\nAssign to another new list" << endl;
  DoublyLinkedList<string> dll6;
  dll6=dll4;
  cout << "list3: " << dll6 << endl;

  // Delete the last 3 nodes
  cout << "\nDelete the last 3 nodes" << endl;
  dll4.removeLast();
  dll4.removeLast();
  dll4.removeLast();
  cout << "list: " << dll4 << endl;

  // Delete the first 3 nodes
  cout << "\nDelete the first 3 nodes" << endl;
  dll4.removeFirst();
  dll4.removeFirst();
  dll4.removeFirst();
  cout << "list: " << dll4 << endl << endl;

  // Check the other two lists
  cout << "\nMake sure the other two lists are not affected." << endl;
  cout << "list2: " << dll5 << endl;
  cout << "list3: " << dll6 << endl;

  // more testing...

  // add test for insertAfter
  cout << "\nInserting Z after node A" << endl;
  auto temp5 = dll6.getFirst();
  while (temp5->obj != "A")
          temp5 = temp5->next;

  dll3.insertAfter(*temp5, "Z");
  cout << "list3: "<< dll6 << endl;

  // add test for insertBefore
  cout << "\nInserting Z before node C" << endl;
  auto temp6 = dll6.getFirst();
  while (temp6->obj != "C")
          temp6 = temp6->next;

  dll6.insertBefore(*temp6, "Z");
  cout << "list3: " << dll6 << endl;

  // add test for removeAfter
  cout << "\nRemove node after node B" << endl;
  auto temp7 = dll6.getFirst();
  while (temp7->obj != "B")
          temp7 = temp7->next;

  dll6.removeAfter(*temp7);
  cout << "list3: " << dll6 << endl;

  // add test for removeBefore
  cout << "\nRemove node before node A" << endl;
  auto temp8 = dll6.getFirst();
  while (temp8->obj != "A")
          temp8 = temp8->next;

  dll6.removeBefore(*temp8);
  cout << "list3: " << dll6 << endl;

  // add test for DoublyLinkedListLength
  cout << "\nTesting List Length for " << endl;
  cout << "list1: " << DoublyLinkedListLength(dll4) << endl;
  cout << "list2: " << DoublyLinkedListLength(dll5) << endl;
  cout << "list3: " << DoublyLinkedListLength(dll6) << endl;

  return 0;
}
