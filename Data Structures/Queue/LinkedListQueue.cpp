//////////////// Queue as Linked List //////////////// 
#include <iostream>
using namespace std;

struct Node{
  string data;
  Node* next;
};

struct Queue{
Node* first;
Node* last;
int length;
public:

Queue(){
  first = NULL;
  last = NULL;
  length = 0;
}

void enqueue(string value);
void dequeue();
void print();
string peek();
};

void Queue::enqueue(string value){ // pointers from first to last;
  Node* newNode = new Node();
  newNode->data = value;
  newNode->next = NULL;
  length++;
  if(first == NULL)first = last = newNode;
  else{
    last->next = newNode;
  }
}

void Queue::dequeue(){
  if(first == NULL) cout << "Queue is empty \n";
  if(first == last)last = NULL; // one Node

    Node* temp = first;
    first=first->next;
    temp->next=NULL;
    temp = NULL;
    length--;
    delete temp;
}
void Queue::print(){
  Node* temp = first;
  if(first == NULL) cout << "Queue is empty \n";
  while(temp != NULL){
    cout << temp->data << endl;
    temp = temp->next;
  }
}

string Queue::peek(){
  if(first == NULL){ return "Queue is empty \n"; return "";}
  else{
    return first->data;
  }
}

int main() {
  Queue q;
  q.enqueue("Joy");
  q.enqueue("Sewar");
  q.print();

  cout << " peek result = " <<  q.peek() << endl;
  q.dequeue();
  q.print();
  
  
}
