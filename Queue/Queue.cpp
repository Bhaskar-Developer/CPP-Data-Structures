#include<bits/stdc++.h>

using namespace std;

class Queue {
  private:
	  struct Node {
	    int data{};
	    Node* next{};

	    //Parameterized constructor for creating a Queue Node with passed value
	    Node(int value) : data{value}, next{nullptr} {}
	  };

	  //Creating the Front and Rear pointer of the Queue
	  Node* front{};
	  Node* rear{};

	  //Helper function for Enqueue function
	  void Enqueue(int value, Node*& front, Node*& rear) {
	    Node* temp = new Node(value);	  
	    if(front == nullptr && rear == nullptr) { //Queue is not yet created or Queue is Empty
	      front = temp;
	      rear = temp;
	      cout << temp->data << " Enqueued to Queue" << '\n';
	    } else {
	      //rear pointer will point to this new node and rear will later become this node	    
	      rear->next=temp;
	      rear=temp;
	      cout << temp->data << " Enqueued to Queue" << '\n';
	    }
	  }     

	  //Helper function for Dequeue function
	  void Dequeue(Node*& front, Node*& rear) {
	    if(front==nullptr && rear == nullptr) {
	      cout << "Queue is Empty!" << '\n';
	    } else {
	      Node* temp = front;
	      front=front->next; //front will be shifted to next node.
	      temp->next=nullptr;
	      cout << temp->data << " Dequeued from Queue" << '\n';
	      delete(temp); //Deleting old front.
	    }
	  }

	  //Display Queue Helper function
	  void displayQueue(Node*& front, Node*& rear) {
	    if(front==nullptr && rear==nullptr) {
	      cout << "Queue Empty" << '\n';
	    } else {   		  
              Node* temp = front;
	      cout << "QUEUE: ";
	      while(temp!=nullptr) {
	        cout << temp->data << " ";
		temp=temp->next;
	      }
	      cout << '\n';
	   }
	  }

	  //Front Helper function:
	  int Front(Node*& front) {
	    return front->data;
	  }

	  //Rear Helper function
	  int Rear(Node*& rear) {
	    return rear->data;
	  }
	  
  public:
	 //Default constructor for class Queue.This will initialize queue object with front and rear pointing to nullptr
	 Queue() : front{nullptr}, rear{nullptr} {}

         //Queue Operations
	 
	 //Enqueue Operaton:
	 void Enqueue(int value) {
	   Enqueue(value,front,rear); //Helper function. This fuction is present in private section of class.
	 }

	 //Dequeue Operation
	 void Dequeue() {
	   Dequeue(front,rear); //Helper Function. This function is present in private secton of class.
	 }

	 //Display Queue
	 //This function is not important. This is only used to see the Queue.
	 void displayQueue() {
	   displayQueue(front,rear); //Helper function. This function is defined in the private section of the class.
	 }

	 //Front: This function return the front element of the Queue
	 void Front() {
	   cout << "Front: " << Front(front) << '\n'; //Helper function. Located on private section of class
	 }

	 //Rear: This function will return the rear element of the Queue
	 void Rear() {
	   cout << "Rear: " << Rear(rear) << '\n'; //Helper function. Located in private section of the class.
	 }

	 //Destructor for Queue.
	 ~Queue() {
	   Node* temp{};
	   while(front!=nullptr) {
	     temp=front;
	     front=front->next;
	     delete temp;
	   }
	   //rear will become nullptr
	   rear=nullptr;
	 }
};

int main() {
  auto queue = make_unique<Queue>();

  //display Queue
  queue->displayQueue();
  
  //Enqueue Operations
  queue->Enqueue(10);
  queue->Enqueue(20);
  queue->Enqueue(30);
  queue->Enqueue(40);
  queue->Enqueue(50);
  
  //display Queue
  queue->displayQueue();

  //Dequeue Operation
  queue->Dequeue();

  //display Queue
  queue->displayQueue();

  //Front Operation
  queue->Front();

  //Rear Operation
  queue->Rear();
}

/*
 Functions Implemented
 1.Enqueue
 2.Dequeue
 3.Front
 4.Rear
 5.Display queue -> just used to display queue, not important
 6.Destructor for Queue.
 7.Constructor for Queue
*/
