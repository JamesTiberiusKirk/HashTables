#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

bool test0() {
  HashTable hashtable1, hashtable2(113);
  
  if (hashtable1.size() != 11) { 
    cout << "Default size for a hashtable should be 11." << endl;
    return false; 
  }
  if (hashtable2.size() < 113) { 
    cout << "Requested a hash table of size 113, but got a table of a smaller size." << endl;
    return false; 
  }
  if (HashTable(12000).size() < 12000) {
    cout << "Requested a hash table of size 12000, but got a table of a smaller size." << endl;
    return false; 
  }
  return true;
}

int main() {
  if (test0()) {
    cout << "Test 0 completed successfully. " << endl;
    return 0;
  }
  cout << "Test 0 failed." << endl;
  return 1;
}
