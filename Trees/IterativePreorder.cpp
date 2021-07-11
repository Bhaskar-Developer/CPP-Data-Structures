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

void Preorder(Tnode *node)
{
  if (node == nullptr)
  {
    return;
  }
  cout << node->data << " ";
  Preorder(node->left);
  Preorder(node->right);
}

void IterativePreorder(Tnode *&node)
{
  //using unordered map to keep track of state of current node
  unordered_map<Tnode *, int> count{};

  //using stack for push and pop operations
  stack<Tnode *> Stack{};

  //pushing root node to stack to start with Inorder Traversal
  Stack.push(node);

  while (!Stack.empty())
  {
    Tnode *current_state = Stack.top();

    //Conditionals for Preorder Traversal using this algorithm
    //data left right : DLR
    //current_state 0: print data
    //current_state 1: push left to stack
    //current_state 2: push right to stack
    //current_state 3: pop the top from stack

    if (current_state == nullptr)
    {
      Stack.pop();
      continue;
    }

    //count[current_state] refers to int(value) part of unordered map

    //Preorder State Conditionals
    //state 0 : print data
    if (count[current_state] == 0)
    {
      cout << current_state->data << " ";
    }
    //state 1 : push left to stack
    else if (count[current_state] == 1)
    {
      Stack.push(current_state->left);
    }
    //state 2 : push right to stack
    else if (count[current_state] == 2)
    {
      Stack.push(current_state->right);
    }
    //state 3 : pop the top of stack
    else
    {
      Stack.pop();
    }

    //increment current_state value after either one of top conditions is met
    count[current_state]++;
  }
}

int main()
{
  Tnode *root = new Tnode(8);
  root->left = new Tnode(3);
  root->right = new Tnode(10);

  //left Subtree
  root->left->left = new Tnode(1);
  root->left->right = new Tnode(6);
  root->left->right->left = new Tnode(4);
  root->left->right->right = new Tnode(7);

  //right Subtree
  root->right->right = new Tnode(14);
  root->right->right->left = new Tnode(13);

  //Recursive Preorder
  cout << "Recursive Preorder: ";
  Preorder(root);
  cout << '\n';

  //Iterative Preorder
  cout << "Iterative Preorder: ";
  IterativePreorder(root);
  cout << '\n';
}