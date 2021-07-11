/*
Deletion of a Node from a Binary Search Tree
3 Cases

Case 1: Node to be deleted has no children/Node to be deleted is a leaf node
-Set the parent's link to this node to null, then delete this node.

Case 2: Node to be deleted has has only one child
-Set the parent's link to this node to point to the child of this node.
-Then delete this node

Case 3: Node to be deleted has 2 children
-Find the minimum of the right subtree/Find the maximum of the left subtree of this node
-copy the minimum value found to this node's data field.
-delete the duplicate value node from the right/left subtree.
*/
/*
			      	12
			      /    \
			     5      15
		  	  /  \    /  \
		  	 3    7  13   17
      	/      \   \    \
   		 1       	9   14  20
			         / \      /
              8   11   18
*/

#include<bits/stdc++.h>

using namespace std;

struct Tnode
{
 int data{};
 Tnode* left{};
 Tnode* right{};

 Tnode(int value) 
	: data{value}, left{nullptr}, right{nullptr} {}
};

void Inorder(Tnode*& node)
{
  if(node == nullptr) return;
  Inorder(node->left);
  cout << node->data << " ";
  Inorder(node->right);
}

Tnode* FindMinimum(Tnode*& node)
{
  Tnode* current = node;
  //go to the left most leaf child
  while(current && current->left != nullptr)
   {
     current = current->left;
   }
  return current;
}

Tnode* Delete(Tnode*& node, const int value)
{
 if(node == nullptr) return node;
 else if(value < node->data) node->left = Delete(node->left,value);
 else if(value > node->data) node->right = Delete(node->right, value);
 //element found, delete that node!!
 else
  {
    //Case 1: Node has no children/Node is a leaf Node
    if(node->left == nullptr && node->right == nullptr)
     {
       delete node;
       node = nullptr;
     }
    //Case 2: Node has only one child

    //first check if left child is null, which means that this node has right child
    //we make the parent of this node to point to the right child of this node
    else if(node->left == nullptr)
     {
       Tnode* temp = node;
       node = node->right;
       delete temp;
     }
    //first check if right child is null, which means that this node has a left child
    //we make the parent of this node to point to the left child of this node
    else if(node->right == nullptr)
     {
       Tnode* temp = node;
       node = node->left;
       delete temp;
     }
    //Case 3: Node has two children
    else
     {
       Tnode* temp = FindMinimum(node->right);
       //the above line can be changed to FindMaximum(node->left)
       //this FindMaximux will return the left most leaf node
       node->data = temp->data;
       node->right = Delete(node->right,temp->data);
     }
  }
 return node;
}

int main()
{
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

  //right subtree
  root->right->left = new Tnode(13);
  root->right->right = new Tnode(17);
  root->right->left->right = new Tnode(14);
  root->right->right->right = new Tnode(20);
  root->right->right->right->left = new Tnode(18);

  //Inorder before Delete
  cout << "Inorder: ";
  Inorder(root);
  cout << endl;

  //Delete Node
  Tnode* root1 = Delete(root,15);
  root = root1;

  //Inorder After Delete
  cout << "Inorder: ";
  Inorder(root);
  cout << endl;
}

/*
This code runs as expected
Convert this code to use void instead of Tnode for the function type
*/
