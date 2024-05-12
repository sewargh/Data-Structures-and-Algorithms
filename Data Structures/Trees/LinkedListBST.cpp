#include <iostream>
#include <stack>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    left = right = NULL;
  }
};

class Tree{
public:
  Node* root;
  
  Tree(){
    root = NULL;
  }
  void insert(int data);
  void remove(int data);
  bool lookup(int data);
  void display();
  void inorder(Node* trav);
};

void Tree::insert(int data){
  Node* newNode = new Node(data); // we allocated memory;
  if(root == NULL){
    root = newNode;
  }
  else {
    Node* traverseP = root; //traverseP => traverse pointer
    Node* holder = traverseP; //holder => of previous node when we loop.
    while(traverseP != NULL)
      {
        holder = traverseP;
        if(data > traverseP->data)        // go to the right
          traverseP = traverseP->right;
        else                               // go to the left
          traverseP = traverseP->left;
      }
    if(data > holder->data )
      holder->right = newNode;
    else
      holder->left = newNode;
  }
}

void Tree::remove(int data){ /////// NOT COMPLETE -- NEEDS MORE STUDYING //////
  if(root == NULL)return;
    
  else{
    Node* traverseP = root;
    Node* holder = NULL;
    bool flag = false;
    
    while(traverseP != NULL && !flag){
      
      if(data > traverseP->data)
        traverseP = traverseP->right;
        
      else if (data < traverseP->data)
        traverseP = traverseP->left;
        
      else {flag = true; break;}
      holder = traverseP; // holder pointes to previous node if data is found;
    }
    
    if (flag){
      //Option 1: No right child:
      //Option 2: Right child which doesnt have a left child
      //Option 3: Right child that has a left child
      if(traverseP->left == NULL && traverseP->right == NULL) // no children;
      {
        if(data > holder->data) // we went right;
          holder->right = NULL;
        else holder->left = NULL;
      }
        
      else if (traverseP->right != NULL){ // if there is right node, we go there; /////////////////////////////
        Node* traverseP2 = traverseP->right;
        //the node I will be deleting is pointed to by traverseP;

        if(traverseP2-> left != NULL){
          if(data > holder->data) //we came from holder->right;
            holder->right = traverseP2->left;
          else holder->left = traverseP2->left;
        }
      }
        
      else if (traverseP->left != NULL) { // no node at right, so we take left node;
        Node* temp = traverseP; //the one I will be deleting

        if(data > holder->data) // we went right;
          holder->right = traverseP->left;

        else holder->left = traverseP->left;

        temp->left = NULL;
        temp = NULL;
        delete temp;
      }
  }
}
}

bool Tree::lookup(int data){
  if(root == NULL)return 0;
  Node* traverseP = root;

  while(traverseP != NULL){
    if(traverseP->data == data)
      return true;
    else if (data > traverseP->data) // go to right
      traverseP = traverseP->right;
    else 
      traverseP = traverseP->left;
  }
  return false;
}

void Tree::display()
{ // this display function uses in-order traversal left->root->right
    /* here we are using stack data structure for traversing */
    stack<Node *> s;
    Node *temp = root;

    while (temp != NULL || s.empty() == false)
    {

        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left; // going towards left first
        }
        temp = s.top();
        cout << temp->data << "  "; // printing the left most data.
        s.pop();

        temp = temp->right; // going towards right.
    }
}

void Tree::inorder(Node* trav){
  // this display function uses in-order traversal left->root->right
  /* here we are using recursion for traversing */
  
  if(trav == NULL) return;
  else {
    inorder(trav->left);
    cout << trav->data << "  ";
    inorder(trav->right);
  }
  /*  //////// postorder //////// 
  
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
  */
  
  /* //////// preorder //////// 

      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
  */
}

int main() {
  Tree b;
  b.insert(20);
  b.insert(10);
  b.insert(30);
  b.insert(25);
  b.insert(40);
  b.insert(1);
  b.display();
  cout << endl;
  b.inorder(b.root);

  cout << endl;
  cout << b.lookup(6);

}
