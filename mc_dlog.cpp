#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"

ulint orderg(ulint, ulint);
ulint log(ulint,ulint,ulint);
ulint modpow(ulint, ulint, ulint);
ulint myRand(ulint);

int main(int argc, char* argv[]){
  if (argc < 4){
    cout << "GIVE ME VALUES"<< endl;
    return 0;
  }
  ulint n,g,a;
  n = atoi(argv[1]);
  g = atoi(argv[2]);
  a = atoi(argv[3]);  

  ulint order = orderg(g,n);
  ulint logs= log(a,g,n);
  
  cout << "Order of g is: " << order << endl;  
  cout << "Logarithm is: " << logs << endl;

  //ulint result = (order % log);
  ulint result = (log%order);

  if (result < 0.00)
     result += order;

  cout << "Result is: " << endl;
  
  return 0;
}

ulint modpow(ulint x,ulint e,ulint m){
  ulint res = 1;  
    x %= m;
  while(e>0){
    if (e%2==1)
      res=(res*x)%m;
    x = (x*x)%m;
    e>>=1;
  }
  return res;
}

ulint myRand(ulint n) {
    srand(time(0));
    return (ulint)rand() % n; 
}

ulint orderg(ulint x, ulint n){
  ulint r, y;
  ulint c1, c2;
  HashTable *Ord = new HashTable();
 
  for(ulint i=0; i<sqrt(n); i++){
    r = myRand(n-1);
    y = modpow(x,r,n);    
    
    c1 = r-Ord->hash_function(y);
    c2 = Ord->hash_function(y)-r;

    if(Ord->findKey(y)){
      if          (c1>0){
        return (r-Ord->hash_function(y));
      } else if   (c2>0){
        return (Ord->hash_function(y)-r);
      } 
    } else {
      Ord->insert(y,r);
    }
  }
     
  return n-1;
}

ulint log(ulint a, ulint g, ulint n){
  HashTable *B = new HashTable();
  HashTable *A = new HashTable();
  ulint r, y, r2;
  for(ulint i=0; i<sqrt(n); i++){
    r = myRand(n-1);
    y = (a*modpow(g,r,n));
    if (B->findKey(y)){
      return B->hash_function(y)-r;
    } else {
      A->insert(y,r);
    }
    
    r2 = myRand(n-1);
    y = modpow(g,r2,n);
    if (A->findKey(y)){
      return A->hash_function(y)-r2;
    } else {
      B->insert(y,r2);
    }
  }

  return 0;
}




