#include<bits/stdc++.h>

using namespace std;

struct Tnode
{
  int data{};
  Tnode *left{nullptr};
  Tnode *right{nullptr};

  Tnode(int value)
      : data{value}, left{nullptr}, right{nullptr} {}
};

void Postorder(Tnode*& node) {
  if(node == nullptr)
    return ;
  Postorder(node->left);
  Postorder(node->right);
  cout << node->data << " ";  
}

void TreeHeight(Tnode*& node) {
  if(node == nullptr)
    return;
  //calculate left height
  int left_height = 1;
  Tnode* left = node->left;
  while(left) {
    left = left->left;
    left_height++;
  }

  //calculate right height
  int right_height = 1;
  Tnode* right = node->right;
  while(right) {
    right = right->right;
    right_height++;
  }
  
  //compare the heights
  //if left_height is greater than right height then tree height is left height or else it is right height
  left_height > right_height ? cout << "Tree Height: " << left_height << '\n': cout << "Tree Height: " << right_height << '\n'; 
}

int main() {
  //root Node
  Tnode *root = new Tnode(12);
  root->left = new Tnode(5);
  root->right = new Tnode(15);

  //left sub tree
  root->left->left = new Tnode(3);
  root->left->left->left = new Tnode(1);
  root->left->right = new Tnode(7);
  root->left->right->right = new Tnode(9);
  root->left->right->right->left = new Tnode(8);
  root->left->right->right->right = new Tnode(11);
  root->left->right->right->right->right = new Tnode(100); 

  //right subtree
  root->right->left = new Tnode(13);
  root->right->right = new Tnode(17);
  root->right->left->right = new Tnode(14);
  root->right->right->right = new Tnode(20);
  root->right->right->right->left = new Tnode(18);
  root->right->right->right->right = new Tnode(90);
  root->right->right->right->right->right = new Tnode(190);
  root->right->right->right->right->right->right = new Tnode(200);

  cout << "Postorder: ";
  Postorder(root);
  cout << '\n';
  TreeHeight(root);
}