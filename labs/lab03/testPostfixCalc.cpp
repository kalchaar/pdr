// Keenan Alchaar | ka5nt | 03/02/21 | testPostfixCalc.cpp

#include <string>
#include <iostream>
#include "stack.h"
#include "postfixCalculator.h"
using namespace std;

int main() {
  postfixCalculator pfcalc;
  string s;
  while (cin >> s) {
    if (s == "+") {
      pfcalc.add();
    } else if (s == "-") {
      pfcalc.subtract();
    } else if (s == "*") {
      pfcalc.multiply();
    } else if (s == "/") {
      pfcalc.divide();
    } else if (s == "~") {
      pfcalc.negate();
    } else {
      int sInt;
      sInt = stoi(s);
      pfcalc.pushNum(sInt);
    }
  }
  cout << pfcalc.getTop() << endl;
  return 0;
}
