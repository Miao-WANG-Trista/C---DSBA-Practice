#include <iostream>
using namespace std;
void position(double x0,double v, double a, int i,double m){
  cout<<"accelaration" <<a <<"\nInitial speed "<<v <<" \nInitial position "<< x0 << "\nNumber of times " << i <<"\nDelta t " <<m<<endl;
  double t=0;
  for (int k=0;k<i;k=k+1){
    double x1=x0 + v*t + 0.5*a*t*t;
  cout<<"At time "<<t<<" the position is "<<x1 <<endl;
  t=t+m;
  }

}

int main() {
  double x0,v,a,m;
  int i;
  cout << "enter the initial position, the speed and the acceleration:\n";
  cin >>x0>>v>>a;
  cout <<"how many times you want to display the position of the moving body?\n";
  cin >>i;
  cout<<"how often (in seconds) you want to update the position of the moving object?\n";
  cin>>m;
  position(x0,v,a,i,m);
return 0;
}