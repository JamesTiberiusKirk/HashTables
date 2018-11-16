/*
 ********************************
 *     Name :Dumitru Vulpe      *
 *     Matric nr: 170017178     *
 *     Module nr: AC21008       *
 ********************************
**/

#ifndef MY_HASH_NODE
#define MY_HASH_NODE

using namespace std;

class HashNode {
  unsigned long key;   // The hash node's key
  unsigned long value; // The key's associated data

  /* extend if necessary */

public:

  HashNode();
  HashNode(unsigned long, unsigned long);
  // Add constructors, destructor if necessary

  unsigned long getKey() { return key; }
  unsigned long getValue() { return value; }
  void assign(unsigned long key, unsigned long value); 

  // extend if necessary
};

/* 
   Implement the assign method 
   and any methods that you may additionally need for the HashTable to work.
*/

HashNode::HashNode(){

}

HashNode::HashNode(unsigned long key, unsigned long value){
  assign(key, value);
}

void HashNode::assign(unsigned long key, unsigned long value){
    this->key=key;
    this->value=value;
}



#endif
