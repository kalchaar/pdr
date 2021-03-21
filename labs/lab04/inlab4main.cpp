#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {


  int *ip = NULL;
  int *ip1 = new int(1);
  int *ip2 = new int(1);
  int *ip3 = new int(2);
  float *f0 = new float(0.0);
  float f = 0.0;
  float *fp = &f;
  float *f1 = new float(1.0);
  float *fn = new float(NULL);
  char *cp = NULL;
  double *dp = NULL;
  
  // cout << i << endl;
  // cout << u << endl;
  // cout << f << endl;
  // cout << d << endl;
  // cout << c << endl;
  // cout << b << endl;
  // cout << ip << endl;
  // cout << cp << endl;
  // cout << dp << endl;
  cout << INT_MAX << endl;
  cout << UINT_MAX << endl;
  return 0;
}
