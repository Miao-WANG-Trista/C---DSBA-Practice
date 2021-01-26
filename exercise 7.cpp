#include <iostream>
using namespace std;
int b,c;
int power1(int a, int n){
  b=b+1;
  if (n==0) return 1;
  for (int i=0;i<=n;i=i+1){
    return a*power1(a,n-1);
  };
}

int power2(int a, int n){
  c=c+1;
  int d;
  if (n==0) return 1;
  if (n==1) return 2;
  if (n%2==0) {
    for (int i=0;i<=n/2;i=i+1)
    d=a*power2(a,n/2-1);
    return d*d;
  }
  if(n%2==1) {
    for (int i=0;i<=(n-1)/2;i=i+1)
    d=a*power2(a,(n-1)/2-1);
    return a*d*d;
  }
}

int main() {
  b=c=0;
  int a,n;
  cout << "Please enter the base and the exponent, both are integer values";
  cin >>a>>n;
  cout<<"the power result of first solution is " <<power1(a,n)<<endl;
  cout<<"the power result of second solution is " <<power2(a,n)<<endl;
  cout <<"the recursive function of first solution has been called "<<b <<" times"<<endl;
  cout <<"the recursive function of second solution has been called "<<c<<" times";
}
// explanation: 
// 1. for the first version: number of recursive calls=n+1; 
// 2. for the second version: number of recursive calls=(n/2)^2