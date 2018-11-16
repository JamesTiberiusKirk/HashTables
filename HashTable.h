/*
 ********************************
 *     Name :Dumitru Vulpe      *
 *     Matric nr: 170017178     *
 *     Module nr: AC21008       *
 ********************************
**/



#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>
#include <list>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

typedef unsigned long ulint;

class HashTable {
  typedef vector <list<HashNode> > Table;
  Table *table; // size of table is stored in the Table data structure
  size_t num;   // number of entries in the HashTable;

public:
  HashTable();       // constructor, initializes table of size 1;
  HashTable(size_t); // constructor, requires size of table as arg
  ~HashTable();      // deconstructor

  size_t size(); // returns size of the hash table (number of buckets)
  size_t hash_function(ulint);  // the table's hash function
  ulint getValue(ulint);    // find and return data associated with key

  void insert(ulint,ulint); // insert data associated with key into table
  void erase(ulint);        // remove key and associated data from table

  void rehash(size_t); // sets a new size for the hash table, rehashes the hash table 
  bool findKey(ulint key);  
  // extend if necessary
};

/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/

HashTable::HashTable(){
  table = new Table(11);

  if (table == NULL)
    throw OUT_OF_MEMORY;

  num = 0;
}

HashTable::HashTable(size_t t_size){
  table = new Table(t_size);

  if (table == NULL)
    throw OUT_OF_MEMORY;

  num = 0;
}

HashTable::~HashTable(){
  delete table;
}

size_t HashTable::size(){
  return table->size();
}

size_t HashTable::hash_function(ulint key){
  return key % table->size();
}

ulint HashTable::getValue(ulint key){
  list<HashNode> *tmpList = &(table->at(hash_function(key)));

  for(HashNode &itr: *tmpList){
    if(key == itr.getKey())
      return itr.getValue(); 
  }
  throw KEY_NOT_FOUND; 
} 

void HashTable::insert(ulint key,ulint val){
  list<HashNode> *tmpList = &(table->at(hash_function(key)));
  HashNode *node = new HashNode(key,val);

  for (list<HashNode>::iterator itr = tmpList->begin(); 
      itr != tmpList->end(); ++itr) {
    if (itr->getKey() == key) { 
      cout<<"DUPS"<<endl;
      cerr<< DUPLICATE_KEY << endl;
      return;
    }
  }

  tmpList->push_back(*node);
  num++;
  
  if (size()<=num)
    rehash(2*size()+1);
} 

void HashTable::erase(ulint key){
  list<HashNode> *hashNodeList = &(table->at(hash_function(key)));
  
  for (list<HashNode>::iterator itr = hashNodeList->begin(); 
      itr != hashNodeList->end(); ++itr) {
    if ((*itr).getKey() == key) {
        hashNodeList->erase(itr); 
        num--; 
        return;
    }
  }
  throw KEY_NOT_FOUND;
}

void HashTable::rehash(size_t newSize){
  Table tmpTable = *table;  
  table->clear();
  //table->resize(newSize);
  table = new Table(newSize);

  for(list<HashNode>& listItr : tmpTable){
    for(HashNode& nodeItr: listItr){
      if(!tmpTable.empty() && !listItr.empty())
        insert(nodeItr.getKey(), nodeItr.getValue());
    }
  }
}

bool HashTable::findKey(ulint key) {
  list<HashNode> *nodeList = &(table->at(hash_function(key)));
  cout << "In the findKey" << endl;
  for (HashNode &itr : *nodeList) {
    if (key == itr.getKey()){
      cout<<"true"<<endl;
      return true;
    }
  }
  cout<<"false"<<endl;
  return false;
}
#endif

