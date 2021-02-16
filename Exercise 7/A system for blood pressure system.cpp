#include <iostream>
#include<vector>
#include<string>
#include<ctime>
#include<typeinfo>
#include<list>
#include<iterator>
using namespace std;

// Define a class named 'Date' to take in the values
class Date
{
public:
    int m_year,m_month,m_day;
    string date_combine;
public:
    Date(){}
    // a constructor to assign values
    Date(int day,int month,int year):m_day{day},m_month{month},m_year{year}{date_combine=to_string(m_day)+"/"+to_string(m_month)+"/"+to_string(m_year);};
    
};

// Define a class named'Blood' to take in the values
class Blood{
  public:
  int s_pressure,d_pressure;
  Date obj_date;
  public:
  // a constructor to assign values
  Blood(int s,int d, Date date):s_pressure{s},d_pressure{d},obj_date{date}{};
  


};

class Patient{
private:
string patient_name;
vector<vector<string>> vect;
vector<string> vec;

public:
// parameterized constructor
Patient(string m):patient_name{m} {};

void addRecord(Blood obj){
  vec.clear();
  vec.push_back(to_string(obj.s_pressure));
  vec.push_back(to_string(obj.d_pressure));
  vec.push_back(obj.obj_date.date_combine);
  vect.push_back(vec);
};

void print(){
 cout<<"This is vect"<<endl;
 for (int i=0;i<vect.size();i++)
    {cout<<endl<<"the "<<i<<" th row:"<<endl;
    for (int k=0;k<vect[0].size();k++)
      cout<<vect[i][k]<<" ";}
};

void printReport(){
  cout<<"Here is the report for "<<patient_name<<endl;
int sum_d=0;
bool a=0;
int max_index=0;

// a loop to go through rows, i here refers to index of rows
for (int i=0;i<vect.size();i++)
// here vect[i][0]refers to each element of the first column standing for systolic blood pressure
 {if (stoi(vect[i][0])>140) {
   a=1;
   if (stoi(vect[i][0])>stoi(vect[max_index][0])) max_index=i;}
   
// the sum of diastolic blood pressure;
sum_d+=stoi(vect[i][1]);
};

double avg_d=sum_d/double(vect.size());
cout<<"the average diastolic blood pressure is: "<<avg_d<<endl;
if (a==0) cout<<"no measurement was too high";
else {
  list<string> max_list;
  // the highest abnormal systolic blood pressures, together with the corresponding diastolic value, and the day it has been measured;
  for (int i=0;i<vect.size();i++){
    if (stoi(vect[i][0])==stoi(vect[max_index][0])){ 
      max_list.push_back(vect[i][0]);
      cout<<"the highest abnormal systolic blood pressure is: " << vect[i][0]<<endl<<"the corresponding diastolic value is: "<<vect[i][1]<<endl<<"the day it has been measured is: "<<vect[i][2];};
  };
 cout<<endl<<"the list of higest systolic blood pressure is: ";
 list<string>::iterator it = max_list.begin();
 for (it = max_list.begin(); it!= max_list.end(); it++)
		cout << *it << " "; 
};

};
};

int main() {

Patient mary("Mary");
mary.addRecord(Blood(94,61, Date(2,5,2013)));
mary.addRecord(Blood(97,65, Date(3,5,2013)));
mary.addRecord(Blood(144,99, Date(4,5,2013)));
mary.addRecord(Blood(123,88, Date(5,5,2013)));
mary.addRecord(Blood(177,110, Date(6,5,2013)));
mary.addRecord(Blood(145,89, Date(7,5,2013)));
mary.printReport();
cout<<endl;
Patient john ("John");
john.addRecord(Blood(88,57, Date(15,5,2013)));
john.addRecord(Blood(95,61, Date(16,5,2013)));
john.addRecord(Blood(114,80, Date(17,5,2013)));
john.addRecord(Blood(151,96, Date(18,5,2013)));
john.addRecord(Blood(176,104, Date(19,5,2013)));
john.addRecord(Blood(176,110, Date(20,5,2013)));
john.printReport();
return 0;
};
