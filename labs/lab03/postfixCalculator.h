// Keenan Alchaar | ka5nt | 03/02/21 | postfixCalculator.h
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"
#include "stackNode.h"
using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  ~postfixCalculator();
  void emptyCheck();
  void pushNum(int n);
  void popNum();
  int getTop();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  
 private:
  stack mainStack;
};

#endif
