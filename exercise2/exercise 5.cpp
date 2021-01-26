#include <iostream>
using namespace std;
//using an iteractive method
int fib(int k){
  int number1=0;
  int number2=1;
  int number3=1;
  for (int i=0;i<=k-3;i=i+1){
    number3=number1+number2;
    number1=number2;
    number2=number3;
  }
  return number3;
}
int main() {
  cout << "Please enter an integer value:\n";
  int j;
  cin >>j;
  cout<<"the "<<j<<" th element of Fibonacci sequence is "<<fib(j);
}