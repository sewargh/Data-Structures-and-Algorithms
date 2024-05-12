#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class Linkedlist{
  private:
    Node* head;
    Node* tail;
  public:
    Linkedlist();
    void append(int value);
    void prepend(int value);
    void printList();
    void insert(int index, int value);
    Node* traverseToIndex(int index);
    void remove(int index);
    void reverse();
};

Linkedlist::Linkedlist(){
  head = tail = NULL;
}
void Linkedlist::append(int value){
  Node *newNode = new Node();
  newNode->data = value;
  if(head == NULL)
  {
    head = tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
  newNode->next = NULL;
}
void Linkedlist::printList(){
  Node* temp = head;
  if(head == NULL) cout << " Empty List \n";
  else{
    while(temp != NULL){
      cout << temp->data << " ---> ";
      temp = temp->next;
    }
      cout << endl;
    }
  delete temp;
}
void Linkedlist::prepend(int value){
  Node* newNode = new Node();
  newNode->data = value;
  if(head == NULL){head = tail = newNode; newNode->next = NULL;}
  else {newNode->next = head; head = newNode;}
}
Node* Linkedlist::traverseToIndex(int index){
  Node* temp = head;
  while( index-- > 0 && temp != NULL){
    temp = temp->next;
  }
  if(temp == NULL) cout << "Index out of bound \n";
  return temp;
}
void Linkedlist::insert(int index, int value){
  Node* newNode = new Node();
  newNode->data = value;
  if (index == 0){prepend(value);}
  else {
    Node* leader = traverseToIndex(index-1); // asssume index is not sent negative;
    if(leader == NULL) return;
    newNode->next = leader->next;
    leader->next = newNode;
    leader = NULL; delete leader; // why do I get an error if I delete leader without assigning it NULL? compiler warning?
  }
}
void Linkedlist::remove(int index){
  if(head == NULL)cout << "Empty list \n";
  else {
    if(index == 0){
      Node* temp = head;
      head = temp->next;
      temp->next = NULL;
      delete temp;
    }
    else{
      Node* leader = traverseToIndex(index-1);
      if (leader->next == NULL || leader == NULL ) {cout << "Index out of bound \n"; return;}
      Node* temp = leader->next;
      leader->next = temp->next;
      temp->next = NULL;
      delete temp;
    }
  }
}

void Linkedlist::reverse(){
  if(head->next == NULL)return; //one node in list;
  
  Node* first = head;
  Node* second = first->next;
  Node* third = NULL;
  tail = head;
  while(second != NULL){ 
    third = second->next;
    second->next = first;
    first = second;
    second = third;
  }

    head->next = NULL;
    head = first;  
}


int main() {
  Linkedlist list;
  list.append(8);
  list.append(2);
  list.printList();
  list.prepend(5);
  list.printList();
  list.insert(1,7);
  list.printList();
  list.insert(4,99);
  list.printList();
  list.remove(6);
  list.printList();
  list.reverse();
  list.printList();

}
