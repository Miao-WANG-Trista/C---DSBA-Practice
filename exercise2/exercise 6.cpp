#include <iostream>
using namespace std;
int i;
int fib(int k){
  
  i=i+1;
  if (k==0||k==1)
  return k;
  else return fib(k-2)+fib(k-3);
}

int main() {
  i=0;
  int j;
 cout << "Please enter an integer value:\n";
 cin >>j;
 cout <<"the "<<j<<"th elements of Fibonacci sequence is " << fib(j)<<endl;
 cout <<"the recursive function has been called " << i<<" times"<<endl;
 
 return 0;
}