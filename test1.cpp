#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

bool test1() {
  HashTable T1(117), T2; 
  HashNode N;

  N.assign(123456789,21008);
  if (N.getKey() != 123456789 || N.getValue() != 21008) {
    cout << "Hash Node values are not stored correctly";
    return false; 
  }

  T1.insert(100,17);
  T1.insert(10,19);
  T1.insert(1000,12);
  if (T1.getValue(100) != 17 || T1.getValue(1000)!=12 || T1.getValue(10) != 19) {
    cout << "Values are not stored correctly." << endl;
    return false;
  }

  T2.insert(2000000,39);
  T2.insert(20000,42);
  T2.insert(2,76);
  if (T2.getValue(2000000) != 39 || T2.getValue(2)!=76 || T2.getValue(20000) != 42) {
    cout << "Values are not stored correctly." << endl;
    return false;
  } 

  return true;
}

int main() {
  if (!test1()) {
    cout << "Test 1 failed." << endl;
    return 1;
  }
  cout << "Test 1 succeeded." << endl;
  return 0;
}
