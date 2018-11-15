#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"

int orderg(int, int);
int log(int,int,int);
int modpow(int, int, int);
int myRand(int);

int main(){
  cout << "Order of g is: " << orderg(5,6) << endl;  
  return 0;
}

int modpow(int x,int e,int m){
  int res = 1;  
    x %= m;
  while(e>0){
    if (e%2==1)
      res=(res*x)%m;
    x = (x*x)%m;
    e>>=1;
  }
  return res;
}

int myRand(int n) {
    srand(time(0));
    return (int)rand() % n; 
}

int orderg(int x, int n){
  int r, y;
  int c1, c2;
  HashTable *Ord = new HashTable();
 
  for(int i=0; i<sqrt(n); i++){
    r = myRand(n-1);
    y = modpow(x,r,n);    
    
    c1 = r-Ord->hash_function(y);
    c2 = Ord->hash_function(y)-r;

    if(Ord->findKey(y)){
      if          (c1>0.00){
        return (r-Ord->hash_function(y));
      } else if   (c2>0.00){
        return (Ord->hash_function(y)-r);
      } 
    } else {
      Ord->insert(y,r);
    }
  }
     
  return n-1;
}

int log(int a, int g, int n){
  int r;
  for(int i=0; i<sqrt(n); i++){
    r = myRand(n-1);
    
  }

  return 0;
}




