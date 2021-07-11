#include<bits/stdc++.h>

using namespace std;

struct Tnode {
  int data{};
  Tnode* right{};
  Tnode* left{};

  Tnode(int value)
      : data{value}, left{nullptr}, right{nullptr} {}
};

//Method 1: Finding and printing Min and Max using Queue
deque<int> Queue{};

void FindMin() {
  cout << Queue.front() << '\n';
}

void FindMax() {
  cout << Queue.back() << '\n';
}

//Method 2: Finding and printing Min and Max using BST property
void FindMinBST(Tnode* node) {
  Tnode* current = node;
  
  while(current && current->left != nullptr) 
    current = current->left;
  
  cout << "Minimum of BST: " << current->data << '\n';   
}

void FindMaxBST(Tnode* node) {
  Tnode* current = node;
  
  while(current && current->right != nullptr) 
    current = current->right;
  
  cout << "Minimum of BST: " << current->data << '\n';   
}

void Inorder(Tnode *&node) {
  unordered_map<Tnode*, int> count{};
  stack<Tnode*> Stack{};

  Stack.push(node);

  while(!Stack.empty()) {
    Tnode* current_state = Stack.top();

    if(current_state == nullptr) {
      Stack.pop();
      continue;
    }

    if(count[current_state] == 0) Stack.push(current_state->left);
    else if(count[current_state] == 1) {
      cout << current_state->data << " ";
      Queue.push_back(current_state->data);
    }
    else if(count[current_state] == 2) Stack.push(current_state->right);
    else Stack.pop();

    count[current_state]++;
  }
}

int main() {

  //root Node
  Tnode *root = new Tnode(12);
  root->left = new Tnode(5);
  root->right = new Tnode(15);

  //left sub tree
  root->left->left = new Tnode(3);
  root->left->left->left = new Tnode(1);
  root->left->left->left->left = new Tnode(0);
  root->left->right = new Tnode(7);
  root->left->right->right = new Tnode(9);
  root->left->right->right->left = new Tnode(8);
  root->left->right->right->right = new Tnode(11);

  //right subtree
  root->right->left = new Tnode(13);
  root->right->right = new Tnode(17);
  root->right->left->right = new Tnode(14);
  root->right->right->right = new Tnode(20);
  root->right->right->right->left = new Tnode(18);
  root->right->right->right->right = new Tnode(22);

  cout << "Inorder: ";
  Inorder(root);
  cout << '\n';
  
  cout << "Method 1: Print Min and Max using Queue" << '\n'; 
  cout << "Minimum of BST: ";
  FindMin();
  cout << "Maximum of BST: ";
  FindMax();
  
  cout << '\n';

  cout << "Method 2: Print Min and Max using BST property" << '\n';
  FindMinBST(root);
  FindMaxBST(root);
}
/*
Method 1:
Queue is used to store the inorder traversal of BST (inorder traversal gives ascending order)
The first and last element of this Queue is printed as Min and Max
Interviewer might ask to not use additional container like Queue
He/she might say to do it without additional container
This can be easily done without QUEUE in Method 2

Method 2:
For all BST the below 2 properties are valid:
1)In every BST the left most leaf node is always the Min
2)In every BST the right most leaf node is always the Max

We leverage these properties to print the Min and Max of the BST
*/