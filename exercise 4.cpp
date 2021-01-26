#include <iostream>
using namespace std;

void floyd(int n){
  for (int i=1;i<=n;i=i+1){
    for (int l=i*(i-1)/2+1;l<=i*(i+1)/2;l=l+1)
    cout <<l<<" ";

    cout <<endl;
  }
}
int main() {
  int n;
 cout << "Please enter an integer:\n";
cin >>n;
cout << "the "<<n<<" laddders of floyd triangle are:"<<endl;
floyd(n);
return 0;
}