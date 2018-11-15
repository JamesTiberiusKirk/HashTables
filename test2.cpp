#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

bool test2() {
  HashTable T1(117); 
  size_t s;

  T1.insert(14598,17);
  T1.insert(234,19);
  T1.insert(3,12);
  s = T1.size();
  T1.rehash(2*s);
  if (T1.size() < 2*s) { 
    cout << "rehash does not work correctly." << endl;
    return false;
  }
  if (T1.getValue(14598) != 17 || T1.getValue(3)!=12 || T1.getValue(234) != 19) {
    cout << "Values are not stored correctly." << endl;
    return false;
  }

  T1.insert(0,39);
  T1.insert(1,42);
  T1.insert(2,76);
  if (T1.getValue(0) != 39 || T1.getValue(2)!=76 || T1.getValue(1) != 42) {
    cout << "Values are not stored correctly." << endl;
    return false;
  } 

  T1.erase(234);
  T1.erase(1);

  if (T1.getValue(14598) != 17 || T1.getValue(3)!=12 || T1.getValue(0) != 39 || T1.getValue(2)!=76) {
    cout << "Values are not stored correctly." << endl;
    return false;
  }

  HashTable T3(173); 
  ulint num = static_cast<ulint>(T3.size());
  for (ulint i=0; i<num; i++) {
    T3.insert(9*i*i+11*i+13,2*i-1);
  }
  for (ulint i=0; i<num; i++) {
    if (T3.getValue(9*i*i+11*i+13) != 2*i-1) {
      cout << "Integer values are not stored correctly." << endl;
      return false;
    }
  }
  for (ulint i=0; i<num; i=i+2) {
    T3.erase(9*i*i+11*i+13);
  }
  for (ulint i=1; i<num; i=i+2) {
    if (T3.getValue(9*i*i+11*i+13) != 2*i-1) {
      cout << "Integer values are not stored correctly after erasing." << endl;
      return false;
    }
  }
  for (ulint i=0; i<num; i=i+2) {
    T3.insert(9*i*i+11*i+13,3*i-1);
  }
  for (ulint i=0; i<num; i++) {
    if (i%2) {
      if (T3.getValue(9*i*i+11*i+13) != 2*i-1) {
	cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
	return false;
      }
    } else {
      if (T3.getValue(9*i*i+11*i+13) != 3*i-1) {
	cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
	return false;
      }
    }
  }
  return true;
}

int main() {
  if (!test2()) {
    cout << "Test 2 failed." << endl;
    return 1;
  }
  cout << "Test 2 succeeded." << endl;
  return 0;
}
