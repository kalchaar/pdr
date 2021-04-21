// Keenan Alchaar | ka5nt | 04/19/2021 | threexinput.cpp
#include <iostream>
#include "timer.h"

using namespace std;

extern "C" long threexplusone(long);

int main() {
  // timer t;
  long x; // initial value 
  long n; // number of iterations
  long result;
  cout << "Enter a number: " << endl;
  cin >> x;
  cout << "Enter iterations of subroutine: " << endl;
  cin >> n;
  // t.start();
  for (int i = 0; i < n; i++) {
    result = threexplusone(x);
  }
  // t.stop();
  cout << "Steps: " << result << endl;
  // cout << "Time taken: " << t.getTime()*1000 << " ms."<< endl;
  return 0;
}
