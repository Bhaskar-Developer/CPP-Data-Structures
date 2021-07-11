#include<bits/stdc++.h>

using namespace std;

class Stack {
  private:
	  struct Node {
	    int data{};
	    struct Node* next{nullptr};

	    //Parameterized constructor for stack node creation with a value and a next pointer
	    Node(int value) : data{value}, next{nullptr} {}
	  };

          //Creating the Top Poinnter for Stack
	  Node* top{};

	  //This pointer is used for the displayStack and Pop function.
	  Node* base{};

	  //This is the helper function for isEmpty() public method. This is also used by the Stack destructor. 
	  bool isEmpty(Node*& top) {
	    if(top==nullptr) {
	      return true;
	    }
	    return false;
	  }

	  //This is the Popper funtion that is used by the destructor to remove all elements from the stack.
	  void Popper(Node*& base, Node*& top) {
	    if(base->next==nullptr) {
	      delete(base);
	      top=nullptr;
	    } else {
	      Node* prev = base;
	      Node* temp{};

	      while(prev->next->next!=nullptr) {
	        prev=prev->next;
	      }
	      temp=prev->next;
	      top=prev;
	      prev->next=nullptr;
	      temp->next=nullptr;
	      delete(temp);
	    }
	  }
  public:
         //Default Constructor for Stack class
	 //This default constructor will create an empty stack object with top pointing to NULL/nullptr.
	 Stack() : top{nullptr} {}
         
	 //Operation of Stack:
	 
	 //Push Operation:
	 void Push(int value) {
	   //Helper Function to Push element into Stack
           Push(top, value);
	 }
         
	 //Helper Function
	 void Push(Node*& top, int data) {
	   if(top == nullptr) { 
	     Node* temp = new Node(data);
	     top=temp;
	     base=temp; 
	     cout << "Pushed " << temp->data << " into Stack" << '\n';
	   } else {
	     Node* temp = new Node(data);
	     top->next = temp;
	     top = temp;
	     cout << "Pushed " << temp->data << " into Stack" << '\n';
	   }
	 }

	 //Pop Operation:
	 void Pop() {
	   if(top == nullptr) {
	     cout << "Stack underflow!" << '\n';
	   } else if(base->next == nullptr) { //There is only one node left in Stack
	     cout << base->data << " Poped from Stack" << '\n';
	     delete(base);
	     top = nullptr;
	   } else {
	     Node* prev = base;
	     Node* temp{};
	     
	     //going till the node just before top node i.e. second last node or the node just before top.
	     while(prev->next->next != nullptr) {
	       prev=prev->next;
	     }
	     //now temp will be the top node, which has to be deleted.
	     //we assign temp to prev and delete temp. Before this we assign top to prev.
	     //This completes the pop operation.
	     temp=prev->next;
	     top=prev;
             prev->next=nullptr;
	     temp->next=nullptr;
	     cout << temp->data << " Poped from Stack" << '\n';
	     delete(temp);
	   }
	 }
	 
	 //Peek Operation:
	 void Peek() {
           if(Peek(top)==0) {
	     cout << "Stack is Empty!" << '\n';
	   } else {
	     cout << Peek(top) << '\n';
	   }
	 }

	 //Helper Function
	 int Peek(Node*& top) {
	   if(top==nullptr) {
	     return 0;
	   }
	   return top->data;
	 }

	 //IsEmpty Operation:
	 void isEmpty() {
	   if(isEmpty(top)) { //This is helper function. It is defined in private part of the class.
	     cout << "Stack Empty" << '\n';
	   } else {
	     cout << "Stack Not Empty" << '\n';
	   }
	 }

	 //Display Stack
	 void displayStack() {
	 Node* temp{};

	 if(top == nullptr) {
	    cout << "Stack is Empty!" << '\n';
	 } else {
         temp = base;
	 cout << "STACK: ";
	 while(temp != nullptr) {
	   cout << temp->data << " ";
	   temp=temp->next;
	 }
         cout << '\n';
	 }
        }

	//Function to empty the Stack. 
	//This function will be called by the Destructor of Stack class to destroy the Stack and free memory
	void makeEmpty(Node*& top) {
	  while(!isEmpty(top)) {
	    Popper(base,top);
	  }
	}
	
	//Destructor for Stack
	~Stack() {
	  makeEmpty(top);
	}
};

int main() {
  auto stack = make_unique<Stack>();
  
  //This should print "Stack is Empty!"	  
  stack->displayStack();
  
  //This should print "Stack Underflow!"
  stack->Pop();  

  //Push Operations
  stack->Push(10); //10 will be pushed to stack. This will print "Pushed 10 into Stack" 
  stack->Push(20); //20 will be pushed to stack. This will print "Pushed 20 into Stack" 
  stack->Push(30); //30 will be pushed to stack. This will print "Pushed 30 into Stack"

  //This should print "STACK: 10 20 30"
  stack->displayStack();
  
  //This wll print "Stack Not Empty"
  stack->isEmpty();

  //This should print 30
  stack->Peek();

  stack->Pop(); //This will pop 30 from stack. This will print "30 Poped from Stack"  
  stack->displayStack(); //This will print "STACK: 10 20"

  stack->Pop(); //This will pop 20 from stack. This will print "20 Poped from Stack"
  stack->displayStack(); //This will print "STACK: 10"

  stack->Pop(); //This will pop 10 from stack. This will print "10 Poped from Stack". Now the stack becomes Empty 
  stack->displayStack(); //This will print "Stack is Empty"
  stack->Peek(); //This will print "Stack is Empty"
  stack->isEmpty(); //This will print "Stack Empty"
}

/*
 Functions Implememted
 1.Push
 2.Pop
 3.Peek
 4.isEmpty
 5.displayStack -> This function is only used to print the contents of the stack. This is not an important function.
 6.Destructor for Stack
 7.Constructor for Stack

 Note: Make it a habit to put helper functions in the private part of the class.

 This program uses linked list to implement Stack. 
 There is no overflow condition as the stack will grow and shrink dynamically during program execution.
*/
