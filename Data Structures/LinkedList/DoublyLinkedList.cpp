#include <iostream>
using namespace std;

struct Node{
int data;
Node* next;
Node* previous;
};


class Linkedlist{
Node* head;
Node* tail;

public:
Linkedlist(){
  head = tail = NULL;
}
void append(int value);
void prepend(int value);
void printList();
void insert(int index, int value);
Node* traverseToIndex(int index);
void remove(int index);
};

void Linkedlist::append(int value){
  Node* newNode = new Node();
  newNode->data = value;
  if(head == NULL){head = tail = newNode; newNode->next = newNode->previous = NULL;}
  else{tail->next = newNode; tail->next = newNode; newNode->next = NULL; newNode->previous = tail; tail = newNode;}
}

void Linkedlist::printList(){
  ////////////// print in order;
  Node* temp = head;
  if(head == NULL) cout << " Empty List \n";
  while(temp != NULL){
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << endl;
  delete temp;

  //////////// print in reverse;
  Node* tempRev = tail;
  while(tempRev != NULL){
    cout << tempRev->data << " --> ";
    tempRev = tempRev->previous;
  }
  cout << endl;
  delete tempRev;
}

void Linkedlist::prepend(int value){
  Node* newNode = new Node();
  newNode->data = value;
  newNode->previous = NULL;
  newNode->next = head;
  head->previous = newNode;
  head = newNode;
}

void Linkedlist::insert(int index, int value){
  Node* newNode = new Node();
  if(index == 0)prepend(value);
  else {
    Node* leader = traverseToIndex(index-1);
    if (leader == NULL ) cout << "Index out of boundary \n";
    else {
      newNode->data = value;
      newNode->next = leader->next; 
      newNode->previous = leader; 
      leader->next = newNode;
      if(newNode->next != NULL){ //index is not last node
        newNode->next->previous = newNode;
      }
      else tail = newNode; //index is last node;
    }
    leader = NULL; delete leader;
  }
}

Node* Linkedlist::traverseToIndex(int index){
  Node* temp = head;
  while (index-- > 0 && temp != NULL){
    temp = temp->next;
  }
  return temp;
}

void Linkedlist::remove(int index){
  if(head == NULL) cout << "Empty list \n";
  if(index == 0){
      Node* temp = head;
      head = head->next;
      head->previous = NULL;
      temp->next = NULL;
      temp = NULL; delete temp;
    }
  else{
    Node* leader = traverseToIndex(index-1);
    if(leader->next == NULL || leader == NULL){ //if asked to delete index after last node;
      cout << "Index out of boundary \n";
      return;
    }
    else if (leader->next->next == NULL){
      Node* temp = leader->next;
      leader->next = temp->next;
      temp->next=temp->previous = NULL;
      temp = NULL; delete temp;
      tail = leader;
      return;
    }
    Node* temp = leader->next;
    leader->next = temp->next;
    temp->next->previous = leader;
    temp->next=temp->previous = NULL;
    temp = NULL; delete temp;
  }
}

int main() {
  Linkedlist list;

  //////////// append + print /////////////
  list.append(1); list.append(8);
  list.printList();
  //////////// prepend + print /////////////
  list.prepend(0); list.prepend(-1);
  list.printList();
  //////////// insert + print /////////////
  list.insert(3, 100);
  list.printList();
  list.insert(5, 99);
  list.printList();
  //////////// remove + print /////////////
  list.remove(0);
  list.printList();
  list.remove(2);
  list.printList();
  list.remove(10);
  list.printList();
  
}
