// Keenan Alchaar | ka5nt | 03/05/21 | stack.cpp

#include <iostream>
#include "stack.h"
#include "stackNode.h"
using namespace std;
// Default constructor; functions as single-linked list
stack::stack() {
  head = new stackNode();
  tail = new stackNode();
  head->next = tail;
  tail->next = NULL;
  count = 0;
}

stack::~stack() {

}

void stack::push(int e) {
  stackNode* newNode = new stackNode();
  newNode->value = e;
  if (count == 0) { // simpler case for count == 0
    head->next = newNode;
    newNode->next = tail;
  } else {
    stackNode* itr = head;
    while (!(itr->next == tail)) { // move toward node next to tail
      itr = itr->next;
    }
    itr->next = newNode; // insertion goes between after this node + before tail 
    newNode->next = tail; // insertion now points toward tail
  }
  count++;
}

void stack::pop() {
  stackNode* itr = head;
  if (count == 1) {
    head->next = tail; // case for count == 1, since itr->next->next will not work correctly on a stack of this size
    itr = itr->next;
    delete itr;
  } else {
    while(!(itr->next->next == tail)) {  // look for node two nodes away from tail
      itr = itr->next;
    }
    stackNode* itr2 = itr->next;         // delete the node next to the tail
    delete itr2;
    itr->next = tail;                    // point the second-from-tail node toward tail
  }
  count--;
}

int stack::top() {
  stackNode* itr = head;
  if (count == 1) {
    return itr->next->value;
  } else {
    while(!(itr->next == tail)) {
    itr = itr->next;
    }
  }
  return itr->value;
}

bool stack::empty() {
  return count == 0;
}
