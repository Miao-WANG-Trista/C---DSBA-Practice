#include <iostream>
#include<exception>
using namespace std;

//  FullStackException that you have to define
class FullStackException:public exception
{
public:
   const char* what()const throw() 
   {
        return "ERROR! The stack is full\n";
   }
};


// EmptyStackException
class EmptyStackException:public exception
{
public:
   const char* what()const throw() 
   {
        return "ERROR! The stack is empty\n";
   }
};

template <typename T>
class StackI{
public:
virtual void push(T t) = 0;
virtual void pop() = 0;
virtual T top() =0;
virtual bool isEmpty() =0;
virtual void print()=0;
};

template <typename T> 
class Stack:public StackI<T>{
protected:
// the index of first element, because stack follows LIFO policy, the index of the first element will move to next position once adding one element, default value is -1, meaning it is an empty stack.
int init_index=-1;

// number of elements in the stack
int num; 
// elements of the stack, uncertain size，we use arrays to construct stacks
T member[]; 
public:
//define two constructors, one that creates a stacks of 20 elements
Stack(){
  member[20];
  num=20;
};
// another that creates a stacks of arbitrary size (i.e. n).
Stack(int n){
  member[n];  
  num=n;
};


//  add an element to the top of the Stack, unless the Stack is full 
void push(T t){
  try
	{
		if(init_index==(num-1))
      throw FullStackException();
    else{init_index++;
member[int(init_index)]=t;};
	}
	catch(FullStackException& me)
	{
		cout<<me.what();
	};

};
// to check if the stack is empty
bool isEmpty()
{
	if(init_index==-1)
		return true;
	else
		return false;
}

// remove the element on the top of the Stack
void pop(){
try
	{
		if(this->isEmpty())
    throw EmptyStackException();
	}
	catch(EmptyStackException& me)
	{
		cout<<me.what();
	}
init_index--;
};
// returns the element on the top of the Stack, unless the Stack is empty
T top(){
try
	{
		if(this->isEmpty())
    throw EmptyStackException();
	}
	catch(EmptyStackException& me)
	{
		cout<<me.what();

	}
return member[int(init_index)];
};
// display the stack elements in between square brackets and from left to to right (the top of the stack being the leftmost element the bottom the rightmost).
void print(){
cout<<"the final result of stack is "<<endl;
if(init_index==-1) cout<<"empty stack"<<endl;
else {
  for (int i=init_index;i>=0;i--)
  {cout<<member[i]<<" ";}
};
};
};

int main(int argc, const char * argv []) {
  Stack<int> s=Stack<int>(3);
  s.print();
  s.push(3);
  s.print();
  s.push(4);
  s.push(2);
  s.push(6);
  s. print ();
  cout<<"current top is: "<<s.top();
  s.pop();
  s. print ();
  s.push(9);
  s. print ();
  s.pop();
  s. print ();
  s.pop();
  s. print ();
  s.pop();
  s. print ();
  s.pop();
  s. print ();
  s.pop();

}
