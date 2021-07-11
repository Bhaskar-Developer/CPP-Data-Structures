/*
Algorithm: This same algorithm can be used for program to print number of nodes with degree 2
CountNodesofDegreeOne(node){
if node == null return 0
if node->left == null  and node->right == null return 0  
if node->left == null  Or node->right == null (node of Degree 1)
  return 1 + CountNodesofDegreeOne(node->left) + CountNodesofDegreeOne(node->left)
return (node of Degree 2) 
CountNodesofDegreeOne(node->left) + CountNodesofDegreeOne(node->left)    
} 
*/

#include<bits/stdc++.h>

using namespace std;

struct Tnode {
  int data{};
  Tnode* left{};
  Tnode* right{};

  Tnode(int value)
      : data{value}, left{nullptr}, right{nullptr} {} 
};

int CountDegreeOne(Tnode*& node) {
  if(node == nullptr) 
    return 0;
  if(node->left == nullptr && node->right == nullptr)
    return 0;
  if(node->left == nullptr || node->right == nullptr) //node of degree 1
    return 1 + CountDegreeOne(node->left) + CountDegreeOne(node->right); 

  return CountDegreeOne(node->left) + CountDegreeOne(node->right);//node of degree 2
}

int main() {
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

  cout << "Number of Nodes with Degree 1: ";
  cout << CountDegreeOne(tree2_root) << '\n';
}
//Review code