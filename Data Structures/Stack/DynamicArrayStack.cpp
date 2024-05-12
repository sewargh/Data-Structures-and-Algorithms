////////////////// Stack as Dynamic Arrays ////////////////// 
#include <iostream>
#include <vector>
using namespace std;

class Stack{
  vector <string> array = {};
  int length; 
  public:
  Stack(){
    length = -1;
  }
  void push(string value);
  void pop();
  string peek();
  void print();
};

void Stack::push(string value){ // the pointers are from top to bottom.
    array.push_back(value);
    length++;
}

void Stack::print(){
  if(length == -1){
    cout << "Stack is empty" << endl;
  }
  else
  for(int i=length; i > -1; i--){
    cout << array[i] << endl;
  }
}

void Stack::pop(){
  if(length == -1){
    cout << "Stack is empty" << endl;
  }
  else {
  array.pop_back();
  length--;
  }
}

string Stack:: peek(){
  if(length == -1){
    return "Stack is empty";
  }
  else
  return array.back();
}

int main() {
  Stack stack;

  ///////// push and print
  stack.push("google");
  stack.push("udemy.com");
  stack.push("youtube");
  stack.print();

  //////////// pop
  cout << "**************** \n";
  stack.pop();
  stack.pop();
  stack.pop();
  cout << "updated stack is \n";
  stack.print();

  ////////////// peek
  cout << "***************** \n";
  cout << stack.peek();
}
