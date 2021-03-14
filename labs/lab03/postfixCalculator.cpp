// Keenan Alchaar | ka5nt | 03/02/21 | postfixCalculator.cpp

#include <stdlib.h>
#include "postfixCalculator.h"
#include "stack.h"
#include "stackNode.h"
using namespace std;

postfixCalculator::postfixCalculator() {
  mainStack = stack();
}

postfixCalculator::~postfixCalculator() {

}

void postfixCalculator::emptyCheck() {
  if (mainStack.empty()) {
    exit(-1);
  }
}

void postfixCalculator::pushNum(int n) {
  mainStack.push(n);
}

void postfixCalculator::popNum() {
  mainStack.pop();
}

int postfixCalculator::getTop() {
  emptyCheck();
  return mainStack.top();
}

void postfixCalculator::add() {
  emptyCheck();
  int top = mainStack.top();
  mainStack.pop();
  emptyCheck();
  int belowTop = mainStack.top();
  mainStack.pop();
  top += belowTop;
  mainStack.push(top);
}

void postfixCalculator::subtract() {
  emptyCheck();
  int top = mainStack.top();
  mainStack.pop();
  emptyCheck();
  int belowTop = mainStack.top();
  mainStack.pop();
  belowTop -= top;
  mainStack.push(belowTop);
}

void postfixCalculator::multiply() {
  emptyCheck();
  int top = mainStack.top();
  mainStack.pop();
  emptyCheck();
  int belowTop = mainStack.top();
  mainStack.pop();
  top *= belowTop;
  mainStack.push(top);
}

void postfixCalculator::divide() {
  emptyCheck();
  int top = mainStack.top();
  mainStack.pop();
  emptyCheck();
  int belowTop = mainStack.top();
  mainStack.pop();
  belowTop /= top;
  mainStack.push(belowTop);
}

void postfixCalculator::negate() {
  emptyCheck();
  int top = mainStack.top();
  mainStack.pop();
  mainStack.push(top*-1);
}
