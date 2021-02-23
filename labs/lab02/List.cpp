// Keenan Alchaar | ka5nt | 02/23/21 | List.cpp

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

}

void List::makeEmpty() {

}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {

}

void List::insertAfter(int x, ListItr position) {

}

void List::insertBefore(int x, ListItr position) {

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

}

void List::remove(int x) {

}

int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
  if (forward) {
    ListItr i = source.first();
    while (!i.isPastEnd()) {
      cout << i.retrieve() << " ";
      i.moveForward();
    }
    cout << endl;
  }
}
