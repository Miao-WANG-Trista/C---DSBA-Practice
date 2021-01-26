#include <iostream>
using namespace std;
void swap(int &a, int &b){
  int c=b;
  b=a;
  a=c;

}
int main() {
  int a,b;
  cout << "Please enter an integer:\n";
  cin >>a;
  cout << "Please enter an integer:\n";
  cin >>b;
  cout <<"Before swap: " << a << b;
  swap(a,b);
  cout <<"After swap: "<< a << b;
return 0;

}