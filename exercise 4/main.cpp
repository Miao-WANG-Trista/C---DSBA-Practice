#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
double x;
double * read_poly(int &n){
  cout << "the degree of the polynomial is: ";
  cin >> n;
  // c stores an array of n+1 doubles
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  // if the coefficient is equal to 0, then won't be displayed
  if (n>0 & c[0]!=0)
    cout << c[0]<< " + ";
  for(i=1;i<n;i++)
  // if the coefficient is 0, continue to next loop, following cout command won't be executed
    {if (c[i]==0) continue;
    // to calculate the real value of a polynomial, we would replace x here with the entered value of unknown
    // cout << c[i] << "*" <<x <<"^" << i << " + ";
    cout << c[i] << "*x^" << i << " + ";};
  if(n>0 & c[n]!=0)
    // cout << c[n] << "*" <<x <<"^" << i <<"=";
    cout << c[n] << "*x^" << i;
  cout << endl;
}
// the function to calculate the value of a polynomial
double calculate_poly (double *c, int n){
  double sum=0;
  cout << "Please enter the value of the unknown" <<endl;
  cin >> x;
  // used power function from cmath library
  for (int i=0;i<=n;i++)
  sum+=c[i]*pow(x,i);
  return sum;
 
}
// the function to get the sum of two polynomials
double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){
  // used max function to limit the size of pointer variable k,dynamic allocation on heap
  double *k=new double[max(d1,d2)];
  // add up the corresponding coefficient of each polynomial one by one
  for (int i=0;i<=max(d1,d2);i++)
  k[i]=p1[i]+p2[i];
  // to determine the degree of sum
  for (int i=max(d1,d2);i>=0;i--){
    if (k[i]!=0){
      dr=i;
      break;
    }}
  return k;
}

// the function to get the product of two polynomials
double * poli_multi(double * p1, int d1, double * p2, int d2, int & dr){
  // the degree of the product result
  dr=d1+d2;
  // a pointer to the result polynomial
  double *k=new double[dr];
  // two loops to multiply each item of one polynomial with all items of another, and add the result to the coefficient of corresponding degree
  for (int i=0;i<=d1;i++){
    for (int m=0;m<=d2;m++)
    k[i+m]+=p1[i]*p2[m];
  }
  return k;
}

int main()
{
  double *p1,result,*p2,*k;
  int g1,d2,dr;

  p1=read_poly(g1);
  p2=read_poly(d2);
  // result=calculate_poly(p1,g1);
  // print_poly(p1,g1);
  // cout<< result;
  // please unremark above three lines to reach answer 1
  // k=poli_sum(p1,g1,p2,d2,dr);
  // cout << "the sum of two polynomial is:" <<endl;
  // print_poly(k,dr);
  // cout <<"the degree of the sum is: " <<dr <<endl;
  // please unremark above 4 lines to reach answer 2
  k=poli_multi(p1,g1,p2,d2,dr);
  cout << "the product of two polynomial is:" <<endl;
  print_poly(k,dr);
  cout <<"the degree of the product is: " <<dr <<endl; 
  delete[] p1;
  delete[] p2;
  delete[] k;
  return 0;
}
