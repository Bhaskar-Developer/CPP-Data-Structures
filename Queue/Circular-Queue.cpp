#include<bits/stdc++.h>

using namespace std;

class CircularQueue {
  private:
	  struct Node {
	    int data{};
	    Node* next{};

	    //Parameterized constructor for Queue Node
	    Node(int value) : data{value}, next{nullptr} {}
	  };

	  //Creating front and rear node.
	  Node* front{};
	  Node* rear{};

	  //Deleting Last Node left out from the Destructor
	  void deleteLastNode() {
	    delete front; //At this point front==rear
	    rear=nullptr;
	  }

  public:
	 //Circular Queue Operations.

         //Enqueue Operation
	 void Enqueue(int value) {	 
	   if(front == nullptr && rear == nullptr) {
	     Node* temp = new Node(value);
	     front=temp;
	     rear=temp;
	     cout << temp->data << " Enqueued to Circular Queue" << '\n'; 
	   } else {
	     Node* temp = new Node(value);
	     rear->next=temp;
	     rear=temp;
	     rear->next=front; //This is the one that makes it circular
	     cout << temp->data << " Enqueued to Circular Queue" << '\n'; 
	   }
	 }

	//Dequeue Operation
	void Dequeue() {
	  if(front==nullptr && rear==nullptr) {
	    cout << "Dequeue Failed! Error: Circular Queue is Empty" << '\n';
	  } else {
	    Node* temp = front;
	    rear->next = front->next; //rear will point to next node
	    front=front->next; //shift front to next node
	    temp->next=nullptr;
	    cout << "Dequeued " << temp->data << " from Circular Queue" << '\n';
	    delete temp;
	  }
	}
	 
	//Display Circular Queue Operation
	void displayCircularQueue() {
	  if(front == nullptr && rear == nullptr) {
	    cout << "Circular Queue Empty!" << '\n'; 
	  } else {
	    Node* temp = front->next;
	    cout << "CIRCULAR QUEUE: " << front->data << " ";
	    while(temp!=front) {
	      cout << temp->data << " ";
	      temp=temp->next;
	    }
	    cout << '\n';
	  }
	}

	//Front Operation
	void Front() {
	  if(front==nullptr && rear==nullptr) {
	    cout << "Circular Queue Empty" << '\n';
	  } else {
	    cout << "Front: " << front->data << '\n';
	  }
	}

	//Rear Operation
	void Rear() {
	  if(front==nullptr && rear==nullptr) {
	    cout << "Circular Queue Empty" << '\n';
	  } else {
	    cout << "Rear: " << rear->data << '\n';
	  }
	}

	//Destructor for Circular Queue
	~CircularQueue() {
	  Node* temp{};
	  while(front!=rear) { //while stops when front==rear 
	    temp=front;
	    front=front->next;
	    delete temp;
	  }
	  deleteLastNode();
	}	
};


int main() {
  auto cq = make_unique<CircularQueue>();

  //Dequeue operation
  cq->Dequeue();
  
  //Front Operation
  cq->Front();
  
  //Rear Operation
  cq->Rear();
  
  //Enqueue Operation
  cq->Enqueue(10);
  cq->Enqueue(20);
  cq->Enqueue(30);
  cq->Enqueue(40);
  cq->Enqueue(50);
  cq->Enqueue(60);

  //Print Circular Queue Operation
  cq->displayCircularQueue();

  //Dequeue Operation
  cq->Dequeue();
  cq->Dequeue();

  //Front Operation
  cq->Front();

  //Rear Operation
  cq->Rear();

  //Displaying Circular Queue after Dequeue Operation
  cq->displayCircularQueue();
}


/*
Operations on Circular Queue
1.Enqueue
2.Dequeue
3.Front
4.Rear
5.Default Construnctor for Circular Queue class
6.Destructor for queue.

The desturctor implemented here will delete the nodes one by one using while loop. 
The nodes will be deleted from front to second last node i.e. node before rear.
The destructor then redirects to another function. This funtion will then delete the last node i.e rear node.
*/   
