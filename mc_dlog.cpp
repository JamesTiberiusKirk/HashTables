/*
 ********************************
 *     Name :Dumitru Vulpe      *
 *     Matric nr: 170017178     *
 *     Module nr: AC21008       *
 ********************************
**/

#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"

ulint orderg(ulint, ulint);
int log(ulint,ulint,ulint);
ulint modpow(ulint, ulint, ulint);

int main(int argc, char* argv[]){
  if (argc < 4){
    cout << "GIVE ME VALUES"<< endl;
    return 0;
  }
  ulint n,g,a;
  g = atoi(argv[1]);
  a = atoi(argv[2]);
  n = atoi(argv[3]);  

  int order = orderg(g,n);
  int logs= log(a,g,n);
  
  cout << "Order of g is: " << order << endl;  
  cout << "Logarithm is: " << logs << endl;

  int result = logs % order;

  if (logs == 0){
    cout<<""<<endl;
    return 0;
  }
  cout << "Result is: " << result << endl;
 
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

ulint orderg(ulint x, ulint n){
  ulint r, y;
  ulint c1, c2;
  HashTable *Ord = new HashTable();
  
  srand(time(NULL));
  for(ulint i=0; i<sqrt(n); i++){
    r = (ulint)rand() % n-1; 
    y = modpow(x,r,n);    
    if(Ord->findKey(y)){
      c1 = r-Ord->getValue(y);
      c2 = Ord->getValue(y)-r;

      if          (c1>0){return c1; 
      } else if   (c2>0){return c2; } 
    
    } else {
      Ord->insert(y,r);
    }
  }
     
  return n-1;
}

int log(ulint a, ulint g, ulint n){
  HashTable *B = new HashTable();
  HashTable *A = new HashTable();
  ulint r, y, r2, res;
  srand(time(NULL));
  for(ulint i=0; i<sqrt(n); i++){
    r = (ulint)rand() % n-1;
    y = (a*modpow(g,r,n));
    cout<<"y: "<< y <<endl; 
    if (B->findKey(y)){
      res = B->getValue(y)-r;
      return res;
    } else {
      A->insert(y,r);
    }
    
    r2 = (ulint)rand() % n-1;
    y = modpow(g,r2,n);
    if (A->findKey(y)){
      res = A->getValue(y)-r2;
      return res;
    } else {
      B->insert(y,r2);
    }
  }

  return 0;
}




