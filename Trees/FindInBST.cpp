#include<bits/stdc++.h>

using namespace std;

struct Tnode {
  int data{};
  Tnode* right{};
  Tnode* left{};

  Tnode(int value)
      : data{value}, left{nullptr}, right{nullptr} {}
};

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
    else if(count[current_state] == 1) 
      cout << current_state->data << " ";
    else if(count[current_state] == 2) Stack.push(current_state->right);
    else Stack.pop();

    count[current_state]++;
  }
}

Tnode* Find(Tnode*& node, const int value) {
  Tnode *current = node;
  
  while(current != nullptr){
  if(value == current->data) 
    return current;
  else if(value < current->data)
    current = current->left;
  else
    current = current->right;  
  }
  
  //not found
  return nullptr;
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

  Tnode* node1 = Find(root, 22);
  
  if(node1 == nullptr) 
    cout << "Not Found" << '\n';
  else
    cout << "Found" << '\n'; 
}