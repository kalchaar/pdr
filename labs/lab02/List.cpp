// Keenan Alchaar | ka5nt | 02/26/21 | List.cpp

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

// Default constructor
List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  head->previous = NULL;
  tail->next = NULL;
  tail->previous = head;
  count = 0;
}

// Copy constructor
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Destructor
List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

// Copy assignment operator
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  return count == 0;
}

void List::makeEmpty() {
  while(!isEmpty()) {
    remove(last().retrieve()); // keep removing from tail until list is empty
  }
}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  ListNode* left = position.current; // becomes left of new node
  ListNode* right = position.current->next;
  newNode->previous = left; // redraw pointers
  newNode->next = right;
  left->next = newNode;
  right->previous = newNode;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  ListNode* left = position.current->previous;
  ListNode* right = position.current; // becomes right of new node
  newNode->previous = left; // redraw pointers
  newNode->next = right;
  left->next = newNode;
  right->previous = newNode;
  count++;
}

void List::insertAtTail(int x) {
  ListNode* n = new ListNode(); // create new pointer to a ListNode which will contain x
  n->value = x; // store x in the new node
  ListNode* prev = tail->previous; // pointer to what should come before the insertion
  n->previous = prev; // this now goes before the insertion
  n->next = tail; // the dummy tail follows the insertion
  tail->previous = n; // the new node is now the previous node to the dummy tail node
  prev->next = n; // the new node is now the next node to the previous node
  count++; // +1 node
}

ListItr List::find(int x) {
  ListItr itr(head->next); // start at dummy head
  for (int k = 0; k < count; k++) { // search and return if found
    if (itr.retrieve() == x) {
      return itr;
    }
    itr.moveForward(); // else continue
  }
  return ListItr(tail); // return tail if not found
}

void List::remove(int x) {
  ListItr itr = find(x);
  if (!itr.isPastEnd()) {
    itr.current->previous->next = itr.current->next; // node left of deletion now points to node right of deletion
    itr.current->next->previous = itr.current->previous; // node right of deletion now points to node left of deletion
    delete itr.current;
    count--;
  }
}

int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
  if (forward) {
    ListItr itr = source.first();
    while (!itr.isPastEnd()) {
      cout << itr.retrieve() << " ";
      itr.moveForward();
    }
    cout << endl;
    return; // break out of function if already printed forward
  } else {
    ListItr itr = source.last();
    while(!itr.isPastBeginning()) {
      cout << itr.retrieve() << " ";
      itr.moveBackward();
    }
    cout << endl;
  }
}
