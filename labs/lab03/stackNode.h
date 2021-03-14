// Keenan Alchaar | ka5nt | 03/05/21 | stackNode.h
#ifndef STACKNODE_H
#define STACKNODE_H

class stackNode {
 public:
  stackNode();

 private:
  int value;       // value in node
  stackNode* next; // pointer to the next node

  friend class stack;

};

#endif
