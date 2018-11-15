#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

bool test3() {
  HashTable T3(17); 
  ulint num = static_cast<ulint>(200*T3.size());
  for (ulint i=0; i<num; i++) {
    T3.insert(i,2*i-1);
  }
  if (T3.size() < static_cast<size_t>(num)) { cout << "Lost some stored values. - Rehashing is not done correctly." << endl; return false; }
  for (ulint i=0; i<num; i++) {
    if (T3.getValue(i) != 2*i-1) {
      cout << "Integer values are not stored correctly after rehashing." << endl;
      return false;
    }
  }
  for (ulint i=0; i<num; i=i+2) {
    T3.erase(i);
  }
  for (ulint i=1; i<num; i=i+2) {
    if (T3.getValue(i) != 2*i-1) {
      cout << "Integer values are not stored correctly after rehashing." << endl;
      return false;
    }
  }
  for (ulint i=0; i<num; i=i+2) {
    T3.insert(i,3*i-1);
  }
  for (ulint i=0; i<num; i++) {
    if (i%2) {
      if (T3.getValue(i) != 2*i-1) {
	cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
	return false;
      }
    } else {
      if (T3.getValue(i) != 3*i-1) {
	cout << "Integer values are not stored correctly after erasing and reinserting." << endl;
	return false;
      }      
    }
  }
  return true;
}

int main() {
  if (!test3()) {
    cout << "Test 3 failed." << endl;
    return 1;
  }
  cout << "Test 3 succeeded." << endl;
  return 0;
}
