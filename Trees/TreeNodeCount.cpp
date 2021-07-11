//CPP program to count total number of nodes in Binary Tree
//This is however Recursive Method

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

int CountNodes(Tnode *&node)
{
  if (node == nullptr)
    return 0;

  //calculate left level/depth
  int left_level = 1;
  Tnode *left = node->left;
  while (left)
  {
    left = left->left;
    left_level++;
  }

  //calculate right level/depth
  int right_level = 1;
  Tnode *right = node->right;
  while (right)
  {
    right = right->right;
    right_level++;
  }

  //if left_level == right_level, then it is a Perfect Binary Tree!
  //Number of nodes in PBT is = 2^level - 1;
  if (left_level == right_level)
  {
    return pow(2, left_level) - 1;
  }
  else
  {
    return 1 + CountNodes(node->left) + CountNodes(node->right);
  }
}

int main()
{
  //This tree rooted at *tree1_root is a Perfect Binary Tree
  //Total Nodes in PBT = 2^level - 1
  Tnode *tree1_root = new Tnode(18);

  //left subtree
  tree1_root->left = new Tnode(15);
  tree1_root->left->left = new Tnode(40);
  tree1_root->left->right = new Tnode(50);

  //right subtree
  tree1_root->right = new Tnode(30);
  tree1_root->right->left = new Tnode(100);
  tree1_root->right->right = new Tnode(40);

  cout << "Number of Nodes in Binary Tree: " << CountNodes(tree1_root) << '\n';

  //This tree rooted at *tree2_root is a Complete Binary Tree
  Tnode *tree2_root = new Tnode(18);

  //left subtree
  tree2_root->left = new Tnode(15);
  tree2_root->left->left = new Tnode(40);
  tree2_root->left->right = new Tnode(50);
  tree2_root->left->right->left = new Tnode(9);
  tree2_root->left->left->left = new Tnode(8);
  tree2_root->left->left->right = new Tnode(7);

  //right subtree
  tree2_root->right = new Tnode(30);
  tree2_root->right->left = new Tnode(100);
  tree2_root->right->right = new Tnode(40);

  cout << "Number of Nodes in Binary Tree: " << CountNodes(tree2_root) << '\n';
}

//see youtube video if you have more doubts
//Note: This program is capable of Calculating total nodes for CBT and PBT only!
//For other types of trees, you can use any one of the tree traversal techniques(inorder,preorder,postorder) to count total nodes in tree