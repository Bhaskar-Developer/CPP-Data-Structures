#include<bits/stdc++.h>

using namespace std;

class SinglyLinkedList {
   private:
	   struct Node {
	      int data{};
	      Node* next{};
	      
	      //Parameterized constructor for Node
	      Node(const int value): 
	         data{value}, next{nullptr} {}
           };   

	   //Defining head and tail Nodes
	   Node* head{};
           Node* tail{};

	  //Calculate the Length of the Singly Linked List
	  //This is used by the insert at specific location method
	  int length() {
	     Node* temp=head;
	     int count=0;
	     while(temp!=nullptr) {
	        count++;
	        temp=temp->next;	
	     } 
	     return count;
	  }

   public:
	  //Default constructor for Singly Linked List
	  SinglyLinkedList() : head{nullptr}, tail{nullptr} {}

	  //Insert Operations:
	  
   	  //Insert value at the tail of the Singly Linked List
	  void insertTail(const int value) {
	     Node* temp = new Node(value);
	     //check if singly linked list is empty.
	     if(head==nullptr && tail==nullptr) {
	        //Linked List is empty. This becomes the first element.
	        head=temp;
		tail=temp;
	        cout<<temp->data<<" inserted at tail"<<endl;
	        return;
	     } 
	     //Linked List is not Empty. Insert the element after tail
	     tail->next=temp;
	     tail=temp;   
	     cout<<temp->data<<" inserted at tail"<<endl;
	  }

	  //insert value at the head of the Singly Linked List
	  void insertHead(const int value) {
	     Node* temp = new Node(value);
	     //Check if singly Linked List is Empty
	     if(head==nullptr && tail==nullptr) {
	        //singly linked list is empty
	        head=temp;
	        tail=temp;
	        return;
	     } 
  	     //Linked List is not empty. Insert this element before the head
	     temp->next=head;
	     head=temp;
	     cout<<temp->data<<" inserted at head"<<endl;
	  }

	  //insert a value at the specified position
   	  void insert(const int value, const int location) {
	     //If invalid location is specified
	     if(location < 1 || location > length()) {
	        cout<<"Error: Invalid Location"<<endl;
	        return;
	     }
    	     //if specified location=1 then insert at head
	     if(location==1) {
                insertHead(value);
	        return;
 	     }
	     //specified location not head.
	     //specified location is after head and between tail. This also includes the tail location.
	     Node* temp = head;
	     //go till location-1		
	     for(int i=0;i<location-2;i++) {
   	        temp=temp->next;
	     }
	     //create a new Node
	     Node* node = new Node(value);
	     node->next=temp->next;
	     temp->next=node; 
	     cout<<node->data<<" inserted at location "<<location<<endl;
          }

	  //Deletion Operations

	  //Delete value at the head
	  void deleteHead() {
	     //check if Linked List is Empty
	     if(head==nullptr && tail==nullptr) {
  	     	cout<<"Linked List is Empty!"<<endl;
	        return;
	     }
	     Node* temp = head;
	     head=head->next;
	     temp->next=nullptr;
	     cout<<temp->data<<" deleted from head"<<endl;
	     delete(temp);
	  }

	  //Delete value at the tail
	  void deleteTail() {
	     //check if Linked List is Empty
	     if(head==nullptr && tail==nullptr) {
	        cout<<"Linked List is Empty!"<<endl;
		return;
	     }
	     //Go till the second last node using loop
	     Node* temp = head;
	     while(temp->next != tail) {
		temp=temp->next;
	     }
	     tail=temp;
 	     Node* temp1 = temp->next;
	     temp->next=nullptr;
	     cout<<temp1->data<<" deleted from tail"<<endl;
	     delete(temp1);
          }

	  //Delete value at entered position/location
	  void deleteAtLocation(const int location) {
	     //check if Linked List is Empty
	     if(head==nullptr && tail==nullptr) {
	        cout<<"Linked List is Empty!"<<endl;
	        return;
	     }
	     //go till one position before the location using loop
	     //i.e. go till location-1
	     Node* temp=head;
	     for(int i=0;i<location-2;i++) {
	        temp=temp->next;
	     }
	     Node* temp1=temp->next;
	     temp->next=temp1->next;
	     temp1->next = nullptr;
	     cout<<temp1->data<<" deleted from location "<<location<<endl;
	     delete(temp1);
	  }

	  //Print Operations

	  //Print the Entire Singly Linked List
	  void print() {
    	     if(head==nullptr) {
	        cout<<"Error:Linked List is Empty"<<endl;
	        return;			
             }
	     cout<<"Singly Linked List: ";
	     //this can be done with while loop as well
	     for(Node* temp=head;temp!=nullptr;temp=temp->next) {
	        cout<<temp->data<<" ";
             }
	     cout<<endl;
          }

	  //get first element of singly linked list
	  void front() {
	     cout<<"Front: "<<head->data<<endl;
	  }
         
          //get last element of singly linked list
	  void back() {
	     cout<<"Back: "<<tail->data<<endl;
  	  }

	  //Reverse Singly Linked List
	  void reverse() {
	     Node* temp=head;
	     Node* current=head;
	     Node* Next{nullptr}; 
             Node* previous{nullptr};
             //using loop to reverse the Linked List by one node per iteration
	     while(current!=nullptr) {
	        Next=current->next;
	        current->next=previous;
	        previous=current;
	        current=Next;	
	     }
	     //swapping head and tail pointers
	     tail=temp;
	     head=previous;
	  }

	  //Destructor for Singly Linked List
	  ~SinglyLinkedList() { 
	     //destroy nodes one by one using Loop
	     while(head!=nullptr) {
	        Node* temp=head;
	        head=head->next;
	        delete(temp);
             }
  	     //set head and tail to nullptr
	     head=nullptr;
	     tail=nullptr;
 	  }
};

int main() {
   auto sll = make_unique<SinglyLinkedList>();
   
   sll->print();

   sll->insertTail(10);
   sll->print();

   sll->insertTail(20);
   sll->print();

   sll->insertTail(30);
   sll->print();

   sll->insertTail(40);
   sll->print();

   sll->insertTail(50);
   sll->print();

   sll->insertHead(60);
   sll->print();

   sll->insertHead(70);
   sll->print();

   sll->insert(80,1);
   sll->print();

   sll->insert(100,20); //This will not be inserted as specified location is not valid.
   sll->print();

   sll->insert(90,8);
   sll->print();

   sll->insert(100,9);
   sll->print();
   
   sll->front();
   sll->back();
   
   sll->deleteHead();
   sll->print();
   sll->front();
   
   sll->deleteTail();
   sll->print();
   sll->back();
   
   sll->deleteAtLocation(5);
   sll->print();

   cout<<"Reversing Singly Linked List"<<endl; 
   sll->reverse();
   sll->print();
}


/*
Operations Implemented

Insertion
1-At Head
2-At Tail
3-At specified location

Deletion
1-At Head
2-At Tail
3-At specified position

Print
1-The entire Linked List
2-Print Head
3-Print Tail

*Reverse Singly Linked List
*Destructor for Singly Linked List
*/
