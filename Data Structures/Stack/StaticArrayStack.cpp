////////////////// Stack as Static Arrays ////////////////// 
#include <iostream>
using namespace std;

class Stack{
  string array[100] = {};
  int length; 
  public:
  Stack(){
    length = -1;
  }
  void push(string value);
  string pop();
  string peek();
  void print();
};

void Stack::push(string value){ // the pointers are from top to bottom.
  if (length < 100)
    array[++length] = value;
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

string Stack::pop(){
  if(length == -1){
    cout << "Stack is empty" << endl;
    return "";
  }
  else {
  string data = array[length];
  array[length]="/0";
  length--;
  return data;
  }
}

string Stack:: peek(){
  if(length == -1){
    return "Stack is empty";
  }
  else
  return array[length];
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
  cout << "pop -> " << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << "updated stack is \n";
  stack.print();

  ////////////// peek
  cout << "***************** \n";
  cout << stack.peek();
}
