////////////////// Stack as Linked List ////////////////// 
#include <iostream>
using namespace std;

struct Node{
  string data;
  Node* next;
};

class Stack{
  Node* top;
  Node* bottom;
  int length; 
  public:
  Stack(){
    top = bottom = NULL;
    length = 0;
  }
  void push(string value);
  string pop();
  string peek();
  void print();
};

void Stack::push(string value){ // the pointers are from top to bottom.
  Node* newNode = new Node();
  newNode->data = value;
  newNode->next = NULL;
  length++;
  if(top == NULL){
    top = bottom = newNode;
  }
  else{
    newNode->next = top;
    top = newNode;
  }
}

void Stack::print(){
  if(top == NULL) cout << "Stack is empty" <<endl;
  Node* temp = top;
  while(temp!=NULL)
    {
    cout << temp->data << endl;
    temp = temp->next;
    }
  delete temp;
}

string Stack::pop(){
  if(top == NULL){cout <<"Stack is empty" <<endl; return "";}
  if( top == bottom) 
    bottom = NULL; // one node;

  Node* temp = top;
  top = top->next;
  string data = temp->data;
  temp->next = NULL;
  delete temp;
  length--;
  
  return data;
}

string Stack:: peek(){
  if(top == NULL)cout <<"Stack is empty \n";
  else {
    return top->data;
  }
  return "";
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
