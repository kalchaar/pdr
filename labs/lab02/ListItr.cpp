// Keenan Alchaar | ka5nt | 02/26/21 | ListItr.cpp

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL) { // if there is nothing after the current node
    return true;
  }
  return false;
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) { // if there is nothing before the current node
    return true;
  }
  return false;
}

void ListItr::moveForward() {
  if (!isPastEnd()) {
    current = current->next;
  }
}

void ListItr::moveBackward() {
  if (!isPastBeginning()) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  return current->value;
}
