#include<bits/stdc++.h>

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

void EmptyBST(Tnode*& node) {
    if(node) {
      EmptyBST(node->left);
      EmptyBST(node->right);
      delete node;
    }
}

public:
  BinarySearchTree()
      : root{nullptr} {}

  BinarySearchTree(Tnode *&rootNode)
      : root{rootNode} {}

void FindMinBST() {
  cout << "Minimum of BST: " << FindMinBST(root) << '\n';
}      

int FindMinBST(Tnode* node) {
  Tnode* current = node;
  
  while(current && current->left != nullptr) 
    current = current->left;
  
  return current->data;   
}

void FindMaxBST() {
  cout << "Maximum of BST: " << FindMaxBST(root) << '\n';
}

int FindMaxBST(Tnode* node) {
  Tnode* current = node;
  
  while(current && current->right != nullptr) 
    current = current->right;
  
  return current->data;   
}       
  void FindBST(const int value){
    Tnode* node1 = Find(root,value);
    
    if(node1 == nullptr) 
      cout << "Not Found" << '\n';
    else
      cout << "Found" << '\n'; 
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

void DeleteNode(const int value) {
  root = Delete(root,value); 
  cout << "Deleting " << value;
  cout << " : { BST: ";
  this->Inorder(this->root);
  cout << "}" << '\n'; 
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
       //this FindMaximum will return the left most leaf node
       node->data = temp->data;
       node->right = Delete(node->right,temp->data);
     }
  }
 return node;
} 
 
 //Destructor for Tree class
~BinarySearchTree() {
   EmptyBST(root);
 }
 
}; 


int main() {
  auto bst = make_unique<BinarySearchTree>();
  bst->insert(12);
  bst->insert(5);
  bst->insert(15);
  bst->insert(3);
  bst->insert(1);
  bst->insert(0);
  bst->insert(7);
  bst->insert(9);
  bst->insert(8);
  bst->insert(11);
  bst->insert(13);
  bst->insert(17);
  bst->insert(14);
  bst->insert(20);
  bst->insert(18);
  bst->insert(22);

  bst->Inorder();
  bst->Preorder();
  bst->Postorder();

  bst->FindMinBST();
  bst->FindMaxBST();
  bst->FindBST(15);
  bst->FindBST(100);
  bst->FindBST(5);
  bst->Inorder();
  bst->DeleteNode(15);
}

/*
Alternate way of destroying/deleting the tree recursively
struct Tnode
  {
    int data{};
    Tnode *left{};
    Tnode *right{};

    Tnode(const int value)
        : data{value}, left{nullptr}, right{nullptr} {}
    This is the destructor
    ~Tnode() {
      delete left;
      delete right;
    }    
  };

  Tnode* root() = new Tnode(5);
  delete root //This delete will recursively delete the entire tree
  try this method on other tress
*/

//BST is finally done
//Code works as per expectation
