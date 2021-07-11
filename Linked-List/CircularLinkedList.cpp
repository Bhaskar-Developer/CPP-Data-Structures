#include<bits/stdc++.h>

using namespace std;

class CircularLinkedList {
  private:
	  struct Node {
	    int data{};
	    Node* next{};

	    //Parameterized Constructor for Node.
	    Node(int value) : data{value}, next{nullptr} {}
	  };

	  //Creating head and tail poniters
	  Node* head{};
	  Node* tail{};

	  //Function to find length of Circular Linked List
	  //The length is used for insertion and deletion operations that are done at a specific location
	  int Length() {
	    Node* temp = head;
	    int count = 0;
	    do {
	      count++;
	      temp=temp->next;
	    }while(temp!=head);
	    return count;
	  }
	  
	  //This is the helper function that is used for insertion at specified location 
	  void insertAt(int value,int location) {
	    //Create new node with the entered value	  
	    Node* newNode = new Node(value);

	    //Creating temp node and pointing it to head. 
	    //This is done for looping from head to the node just before the specified location
	    Node* temp = head;
	    for(int i=1;i < location-1;i++) {
	      temp=temp->next;
	    }

	    //This is the next node i.e. node after temp's current location
	    //This is become the next node since the new node will be inserted before this node
            Node* next = temp->next;

	    //pointing the next of the newly created node to next node
	    newNode->next=next;
	    //temp->next will point to this new node.
	    temp->next=newNode;

            cout << "Inserted " << newNode->data << " at location " << location << "." << '\n';	    
	  }

	  //This is the helper function that is used to delete value from specific loaction
	  void deleteAt(int location) {
	    //going till the node location before the specified location.	  
	    Node* temp=head;
	    for(int i=1;i<location-1;i++) {
	      temp=temp->next;
	    }

	    //Node to be deleted
	    Node* deleteNode=temp->next;
	    temp->next=deleteNode->next;
	    deleteNode->next=nullptr;
	    cout << "Deleted " << deleteNode->data << " from location " << location << "." << '\n';
	    delete deleteNode;
	  }
	     
	    //This function deleted the last node that was left out by the while loop in the destructor
	    void deleteLastNode() {
	      delete head; //head=tail at this point. Deleting the only remaining node
	      tail=nullptr;
	    }

  public:
	 //Default constructor for Circular Linked List
	 CircularLinkedList() : head{nullptr}, tail{nullptr} {}
	 
	 //Operations on circular Linked List
	 
	 //Insertion Operations:
	 
	 //Insertion at head
	 void insertHead(int value) {
	   Node* temp = new Node(value);	 
	   if(head==nullptr && tail==nullptr) {
	     head=temp;
	     tail=temp;
	     tail->next=head;
	     cout << head->data << " inserted at Head of Circular Linked List" << '\n';
	   } else {
	     temp->next=head;
	     tail->next=temp;
	     head=temp;
	     cout << head->data << " inserted at Head of Circular Linked List" << '\n';
	   }
	 }

	 //Insertion at Tail
	 void insertTail(int value) {
	   if(head==nullptr && tail==nullptr) {
	     cout << "Circular Linked List is Empty" << '\n';  
	   } else {
	     Node* temp = new Node(value);
	     tail->next=temp;
	     temp->next=head;
	     tail=temp;
	     cout << tail->data << " inserted at Tail of Circular Linked List" << '\n';
	   }
	 }

	 //Insertion at specified location
	 void insertAtLocation(int value,int location) {
	   //If specified locaion is 1 then insert the element at head of Circular Linked List	 
	   if(location==1) {
	     insertHead(value);
	     return;
	   }

	   //This will execute if the entered location is not a valid location
	   if(location < 0 || location > Length()) {
	     cout << "Thats an invalid location!" << '\n';
	     return;
	   }

	   //If the specified location is a different location i.e. 
	   //its a tail location or another location but not head then this will execute
	   insertAt(value,location);
	 }

	 //Delete Operations:
	 void deleteHead(){
	   if(head==nullptr && tail==nullptr) {
	     cout << "Circular Linked List is Empty" << '\n';
	   } else {
	     Node* temp = head;
	     tail->next=head->next;
	     head=head->next;
	     temp->next=nullptr;
	     cout << "Deleted " << temp->data << " from Head of Circular Linked List" << '\n';
	     delete temp;
	   }
	 }

	 //Delete Tail
	 void deleteTail() {
	   if(head==nullptr && tail==nullptr) {
	     cout << "Circular Linked List s Empty" << '\n';
	   } else {
	     //using the logic of going to the node just before tail.
	     Node* previous = head;
	     while(previous->next!=tail) {
	       previous=previous->next;
	     }
	     Node* temp = previous->next;
	     previous->next = temp->next;
	     tail=previous;
	     temp->next=nullptr;
	     cout << "Deleted " << temp->data << " from Tail of Circular Linked List" << '\n';
	     delete temp;
	   }
	 }

	 //Deletion at specified location
         void deleteAtLocation(int location) {
	   //deletion at head i.e. if entered location is 1
	   if(location==1) {
	     deleteHead();
	     return;
	   }

	   //If entered location is invalid
	   if(location < 0 || location > Length()) {
	     cout << "Thats an invalid location!" << '\n';
	     return;
	   }

	   //if location is any location but is not head or if location is tail
	   deleteAt(location); 
	 }	 

	 //Print Operations:

	 //Print Circular Linked List
	 void printCircularLinkedList() {
	   if(head==nullptr && tail==nullptr) {
	     cout << "Circular Linked List is Empty" << '\n';
	   } else {
	     Node* temp = head->next;
	     cout << "CIRCULAR LINKED LIST: " << head->data << " ";
	     while(temp!=head) {
	       cout << temp->data << " ";
	       temp=temp->next; 
	     }
	     cout << '\n';
	   }
	 }

	 //Print Head of Circular Linked List
	 void printHead() {
	   cout << "Head: " << head->data << '\n';
	 }

	 //Print Tail of Circular Linked List
	 void printTail() {
	   cout << "Tail: " << tail->data << '\n';
	 }

	 //Reverse Circular Linked List:
	 void reverseCircularLinkedList() {
	   Node* current = head;
	   Node* previous{nullptr};
	   Node* Next{nullptr};
	   Node* temp = head;
	   do {
	     Next=current->next; //Next points to the next node of current node
	     current->next=previous; //point the next of current node to the previous node. This reverses the direction od the List
	     previous=current; //shift previous to next node i.e. current
	     current=Next; //shift current to next node i.e Next
	   } while(current!=head);

	   //Now head and tail will be interchanged.
	   tail=temp; //temp is pointing to head
	   head=previous; //after the loop completes previous will reach the end of the list in reverse. 
	   //We simply assig this to tail pointer;
	   tail->next=head; //tail->next has to point to head as this is a Circular Linked List
	   cout << "Circular Linked List has been reversed" << '\n';
	 }

	 //Destructor for Circular Linked List
	 ~CircularLinkedList() {
	   Node* temp=head;
	   while(head!=tail) { //this loop stops when head=tail
	     temp=head;	   
	     head=head->next;
	     delete temp;
	   }
	   //This while loop still leaves one node undeleted. 
	   //We delete that one remaining node by calling this function below;
	   deleteLastNode();
	 }
};


int main() {
  auto cll = make_unique<CircularLinkedList>();

  //Print Circular Linked List
  cll->printCircularLinkedList();

  //Insertion at Head
  cll->insertHead(10);
  cll->insertHead(20);
  cll->insertHead(30);
  cll->insertHead(40);

  //Print Circular Linked List
  cll->printCircularLinkedList();

  //Insertion at tail
  cll->insertTail(50);
  cll->insertTail(60);
  cll->insertTail(70);
  cll->insertTail(80);
  cll->insertTail(90);

  //Print Circular Linked List
  cll->printCircularLinkedList();

  //Print Head of Circular Linked List
  cll->printHead();

  //Print Tail of Circular Linked List
  cll->printTail();

  //Insert at specified locations
  
  //Specified Location is 1 i.e. insert at head
  cll->insertAtLocation(100,1);
  cll->printCircularLinkedList();

  //Specified location is invalid
  cll->insertAtLocation(101,25);

  //Specified location is any location within the circular linked list
  cll->insertAtLocation(200,6);
  cll->printCircularLinkedList();

  //Specified location is tail location in the linked list
  cll->insertAtLocation(300,11);
  cll->printCircularLinkedList();

  //Delete head
  cll->deleteHead();
  cll->printCircularLinkedList();

  //Delete Tail
  cll->deleteTail();
  cll->printCircularLinkedList();

  //Delete at Specific locations

  //Specified location is 1 i.e. delete head node
  cll->deleteAtLocation(1);
  cll->printCircularLinkedList();

  //Specified location is invalid
  cll->deleteAtLocation(25);

  //Specified location is any location within the circular linked list
  cll->deleteAtLocation(5);
  cll->printCircularLinkedList();

  //Specified location is tail of linked list
  cll->deleteAtLocation(8);
  cll->printCircularLinkedList();

  //Reverse Circular Linked List
  cll->reverseCircularLinkedList();
  cll->printCircularLinkedList();

  //Reverse Circular Linked List
  cll->reverseCircularLinkedList();
  cll->printCircularLinkedList();
}

/*
Functions Implemented:

A.Insertion Operation
1.At head
2.At tail
3.At specified location

B.Deletion Operation
1.At head
2.At tail
3.At specified location

C.Print Operation
1.Print head
2.Print tail
3.Print entire Circular Linked List

D.Reverse
1.Reverse Circular Linked List
*/
