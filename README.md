# DoubleLinkedList/ImplementingQueue Project

### Description

This project has two parts,

 - Part1:  Is a C++ implementation of a DoublyLinkedList for generic and integer types. 
    - The <u>DoublyLinkedList</u> program creates a double linked list using pointers and nodes. In this program, we create 3 different lists, by adding, removing, copying, from the front and back of the list using integers. The methods below describe how the program works. 
       - copy constructor method that inserts a new node
       - destructor method that deletes a node. 
       - The assignment operator deletes the whole list and if list is not empty, copy all the elements over to the new list.
       -  insertFirst() method allows user to insert the new node in the front of the list
       - insertLast() method allows user to insert the new node in the back of the list 
       - removeFirst() method allows user to remove the node from the front of the list.
       - removeLast() method allows user to remove the node from the back of the list.
       - first() method returns the first node in the list, or if its empty, returns 'Empty Doubly Linked List'
       - last() method returns the last node in the list, or if its empty, returns 'Empty Doubly Linked List'
       - insertAfter() method inserts a new node after the node p. 
       - insertBefore() method inserts a new node before the node p. 
       - removeAfter() method removes a node after the node p.
       - removeBefore() method removes a node before the node p.
       - DoublyLinkedListLength() method returns the length of the called list.
    - The <u>TemplatedLinkedList</u> program does the same thing the DoublyLinkedList does but it uses characters inside the lists instead of integers. All the same methods are used as shown in above. 
 - Part 2:  Is a C++ implementation of MinQueue data structure that can store comparable elements. 
    - The <u>MinQueue</u> program creates a queue list implementing enQueue(), and deletes the list by implementing deQueue(). The program also uses que.size() to find the length of the list and que.min() to print out the minimum element inside of the list. 

### To Run

Using terminal on Mac,

DoubleLinkedList
```
$ cd DoubleLinkedList-ImplementingQueue
$ cd DoubleLinkedList 
$ cd DoublyLinkedList
$ /main
```

TemplateDoublyLinkedList
```
$ cd DoubleLinkedList-ImplementingQueue
$ cd ImplementingQueue
$ cd MinQueue
$ /Main
```

ImplementingQueue
```
$ cd DoubleLinkedList-ImplementingQueue
$ cd ImplementingQueue
$ cd MinQueue
$ /a.out
```

### Output

When the above programs are ran, they should look like this..

<u>DoublyLinkedList</u>

![DoublyLinkedList](https://github.com/azamzow/DoubleLinkedList-ImplementingQueue/blob/master/DoubleLinkedList/DoublyLinkedList.png?raw=true)



<u>TemplatedLinkedList</u> 

![TemplateDoublyLinkedListPart1](https://github.com/azamzow/DoubleLinkedList-ImplementingQueue/blob/master/DoubleLinkedList/TemplateDoublyLinkedListPart1.png?raw=true)



![TemplateDoublyLinkedListPart2](https://github.com/azamzow/DoubleLinkedList-ImplementingQueue/blob/master/DoubleLinkedList/TemplateDoublyLinkedListPart2.png?raw=true)





<u>MinQueue</u>

![MinQueue](https://github.com/azamzow/DoubleLinkedList-ImplementingQueue/blob/master/ImplementingQueue/MinQueue.png?raw=true)
