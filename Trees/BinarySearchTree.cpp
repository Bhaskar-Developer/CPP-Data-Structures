#include <bits/stdc++.h>

using namespace std;

class BinarySearchTree
{
private:
  struct Tnode
  {
    int data{};
    Tnode *left{};
    Tnode *right{};

    Tnode(const int value)
        : data{value}, left{nullptr}, right{nullptr} {}
  };

  Tnode *root{};

public:
  BinarySearchTree()
      : root{nullptr} {}

  BinarySearchTree(Tnode *&rootNode)
      : root{rootNode} {}

  void insert(const int value)
  {
    if (root == nullptr)
    {
      this->root = new Tnode(value);
    }
    else
    {
      this->insert(value, this->root);
    }
  }

  void insert(const int value, Tnode *&node)
  {
    if (value == node->data)
    {
      cout << "This value already exists!" << '\n';
      return;
    }
    if (value < node->data)
    {
      if (node->left == nullptr)
      {
        node->left = new Tnode(value);
      }
      else
      {
        this->insert(value, node->left);
      }
    }
    else
    {
      if (value > node->data)
      {
        if (node->right == nullptr)
        {
          node->right = new Tnode(value);
        }
        else
        {
          this->insert(value, node->right);
        }
      }
    }
  }

  void Inorder()
  {
    cout << "Inorder Traversal: ";
    this->Inorder(this->root);
    cout << '\n';
  }

  void Inorder(Tnode *&node)
  {
    unordered_map<Tnode *, int> count{};
    stack<Tnode *> Stack{};

    Stack.push(node);

    while (!Stack.empty())
    {
      Tnode *current_state = Stack.top();

      if (current_state == nullptr)
      {
        Stack.pop();
        continue;
      }

      if (count[current_state] == 0)
        Stack.push(current_state->left);
      else if (count[current_state] == 1)
        cout << current_state->data << " ";
      else if (count[current_state] == 2)
        Stack.push(current_state->right);
      else
        Stack.pop();

      count[current_state]++;
    }
  }

  void Preorder()
  {
    cout << "Preorder Traversal: ";
    this->Preorder(this->root);
    cout << '\n';
  }

  void Preorder(Tnode *&node)
  {
    unordered_map<Tnode *, int> count{};
    stack<Tnode *> Stack{};

    Stack.push(node);

    while (!Stack.empty())
    {
      Tnode *current_state = Stack.top();

      if (current_state == nullptr)
      {
        Stack.pop();
        continue;
      }

      if (count[current_state] == 0)
        cout << current_state->data << " ";
      else if (count[current_state] == 1)
        Stack.push(current_state->left);
      else if (count[current_state] == 2)
        Stack.push(current_state->right);
      else
        Stack.pop();

      count[current_state]++;
    }
  }

  void Postorder()
  {
    cout << "Postorder Traversal: ";
    this->Postorder(this->root);
    cout << '\n';
  }

  void Postorder(Tnode *&node)
  {
    unordered_map<Tnode *, int> count{};
    stack<Tnode *> Stack{};

    Stack.push(root);

    while (!Stack.empty())
    {
      Tnode *current_state = Stack.top();

      if (current_state == nullptr)
      {
        Stack.pop();
        continue;
      }

      if (count[current_state] == 0)
        Stack.push(current_state->left);
      else if (count[current_state] == 1)
        Stack.push(current_state->right);
      else if (count[current_state] == 2)
        cout << current_state->data << " ";
      else
        Stack.pop();

      count[current_state]++;
    }
  }
};

int main()
{
  auto bst = make_unique<BinarySearchTree>();
  bst->insert(10);
  bst->insert(20);
  bst->insert(8);
  bst->insert(22);
  bst->insert(18);

  bst->Inorder();
  bst->Preorder();
  bst->Postorder();
}