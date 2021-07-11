//Program to count Leaf nodes in a binary tree
//Twisted question: Program to count nodes with degree 0
/*
Algorithm:
GetLeafCount(node)
1) If node is NULL then return 0.
2) Else If left and right child nodes are NULL return 1.
3) Else recursively calculate leaf count of the tree using below formula.
    Leaf count of a tree = Leaf count of left subtree[GetLeafCount(node->left)] +
    Leaf count of right subtree[GetLeafCount(node->right)]
*/

#include <bits/stdc++.h>

using namespace std;

struct Tnode
{
  int data{};
  Tnode *left{nullptr};
  Tnode *right{nullptr};

  Tnode(int value)
      : data{value}, left{nullptr}, right{nullptr} {}
};

int GetLeafCount(Tnode *&node)
{
  if (node == nullptr)
    return 0;
  else if (node->left == nullptr && node->right == nullptr)
    return 1;
  else
    return GetLeafCount(node->left) + GetLeafCount(node->right);
}

int main()
{
  Tnode *tree1_root = new Tnode(18);

  //left subtree
  tree1_root->left = new Tnode(15);
  tree1_root->left->left = new Tnode(40);  //leaf
  tree1_root->left->right = new Tnode(50); //leaf

  //right subtree
  tree1_root->right = new Tnode(30);
  tree1_root->right->left = new Tnode(100); //leaf
  tree1_root->right->right = new Tnode(40); //leaf
  //Total 4 leaf nodes

  cout << "Number of Leaf Nodes: " << GetLeafCount(tree1_root) << '\n';

  Tnode *tree2_root = new Tnode(18);

  //left subtree
  tree2_root->left = new Tnode(15);
  tree2_root->left->left = new Tnode(40);
  tree2_root->left->right = new Tnode(50);
  tree2_root->left->right->left = new Tnode(9); //leaf
  tree2_root->left->left->left = new Tnode(8);  //leaf
  tree2_root->left->left->right = new Tnode(7); //leaf

  //right subtree
  tree2_root->right = new Tnode(30);
  tree2_root->right->left = new Tnode(100); //leaf
  tree2_root->right->right = new Tnode(40); //leaf
  //Total 5 leaf nodes

  cout << "Number of Leaf Nodes: " << GetLeafCount(tree2_root) << '\n';

  //Tree with only root node
  //Leaf node count is 1
  Tnode *tree3_root = new Tnode(10);
  cout << "Number of Leaf Nodes: " << GetLeafCount(tree3_root) << '\n';
}