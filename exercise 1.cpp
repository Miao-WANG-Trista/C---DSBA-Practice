#include <iostream>
#include <cmath>
using namespace std;

void check_point(double x,double y,double c,double d, double e){
  double k1=fabs(x-c);
  double k2=fabs(y-d);
  double distance=sqrt(k1*k1+k2*k2);
  if (distance<=e)
  cout<<"the point is in the circle";
  else cout<<"the point isn't in the circle";
}
int main() {
  double x,y,c,d,e;
  cout << "Please enter the x-coordinate\n";
  cin>>x;
  cout << "Please enter the y-coordinate\n";
  cin>>y;
  cout << "Please enter the x-coordinate of the circle\n";
  cin >>c;
  cout << "Please enter the y-coordinate of the circle\n";
  cin >>d;
  cout << "Please enter the radius of the circle\n";
  cin>>e;
  check_point(x,y,c,d,e);
return 0;
}