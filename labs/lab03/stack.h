// Keenan Alchaar | ka5nt | 03/05/21 | stack.h
#ifndef STACK_H
#define STACK_H

#include "stackNode.h"

using namespace std;

class stack {
 public:
  stack();
  ~stack();
  void push(int e);
  void pop();
  int top();
  bool empty();
 private:
  stackNode* head;
  stackNode* tail;
  int count;
};

#endif
