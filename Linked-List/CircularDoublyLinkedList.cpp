#include <bits/stdc++.h>

using namespace std;

class CircularDoublyLinkedList
{
private:
  struct Node
  {
    int data{};
    Node *next{}, *prev{};

    Node(int value)
        : data{value}, prev{nullptr}, next{nullptr} {}
  };

  Node *head{};
  Node *tail{};

  int Length()
  {
    Node *temp = this->head;
    int count = 0;
    do
    {
      count++;
      temp = temp->next;
    } while (temp != head);
    return count;
  }

public:
  CircularDoublyLinkedList()
      : head{nullptr}, tail{nullptr} {}

  void Print()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "CDLL: Empty" << '\n';
      return;
    }

    Node *temp = this->head;
    cout << "CDLL: ";
    do
    {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << '\n';
  }

  void PrintReverse()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "CDLL: Empty" << '\n';
      return;
    }

    Node *temp = this->tail;
    ;
    cout << "Reversed CDLL: ";
    do
    {
      cout << temp->data << " ";
      temp = temp->prev;
    } while (temp != tail);
    cout << '\n';
  }

  void PrintHead()
  {
    cout << "Head: " << this->head->data << '\n';
  }

  void PrintTail()
  {
    cout << "Tail: " << this->tail->data << '\n';
  }

  void insertAtHead(int const value)
  {
    if (head == nullptr && tail == nullptr)
    {
      Node *temp = new Node(value);
      temp->next = temp;
      temp->prev = temp;
      this->head = temp;
      this->tail = temp;
    }
    else
    {
      this->insertAtHead(value, this->head);
    }
  }

  void insertAtHead(const int value, Node *&head)
  {
    Node *temp = new Node(value);
    temp->next = this->head;
    temp->prev = this->tail;
    this->head->prev = temp;
    this->tail->next = temp;
    this->head = temp;
  }

  void insertAtTail(const int value)
  {
    if (head == nullptr && tail == nullptr)
    {
      Node *temp = new Node(value);
      temp->next = temp;
      temp->prev = temp;
      this->head = temp;
      this->tail = temp;
    }
    else
    {
      this->insertAtTail(value, this->tail);
    }
  }

  void insertAtTail(const int value, Node *&tail)
  {
    Node *temp = new Node(value);
    temp->prev = this->tail;
    temp->next = this->head;
    this->tail->next = temp;
    this->head->prev = temp;
    this->tail = temp;
  }

  void insertAtLocation(const int value, const int location)
  {
    if (location == 1)
    {
      this->insertAtHead(value);
      return;
    }
    if (location < 1 || location > this->Length())
    {
      cout << "Invalid Location" << '\n';
      return;
    }

    this->insertAtLocation(value, this->head, location);
  }

  void insertAtLocation(const int value, Node *&head, const int location)
  {
    Node *node = new Node(value);
    Node *temp = this->head;
    for (int i = 1; i < location - 1; i++)
    {
      temp = temp->next;
    }
    Node *next = temp->next;
    node->next = next;
    node->prev = temp;
    temp->next = node;
    next->prev = node;
  }

  void deleteHead()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "CDLL: Empty" << '\n';
      return;
    }

    Node *temp = this->head;
    Node *next = temp->next;
    next->prev = temp->prev;
    this->tail->next = next;
    this->head = next;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete (temp);
  }

  void deleteTail()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "CDLL: Empty" << '\n';
      return;
    }

    Node *previous = this->head;
    while (previous->next != tail)
    {
      previous = previous->next;
    }

    Node *temp = previous->next;
    previous->next = temp->next;
    this->head->prev = previous;
    this->tail = previous;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete (temp);
  }

  void deleteAtLocation(const int location)
  {
    if (location == 1)
    {
      this->deleteHead();
      return;
    }
    if (location < 1 || location > this->Length())
    {
      cout << "Invalid Location" << '\n';
      return;
    }

    Node *previous = this->head;
    for (int i = 1; i < location - 1; i++)
    {
      previous = previous->next;
    }

    Node *current = previous->next;
    Node *Next = current->next;

    previous->next = current->next;
    Next->prev = previous;
    current->prev = nullptr;
    current->next = nullptr;
    delete (current);
  }

  ~CircularDoublyLinkedList()
  {
    delete (this->head);
    delete (this->tail);
  }
};

int main()
{
  auto cdll = make_unique<CircularDoublyLinkedList>();
  cdll->insertAtHead(1);
  cdll->Print();
  cdll->insertAtHead(2);
  cdll->Print();
  cdll->insertAtHead(3);
  cdll->Print();
  cdll->insertAtHead(4);
  cdll->Print();
  cdll->insertAtHead(5);
  cdll->Print();
  cdll->insertAtTail(10);
  cdll->Print();
  cdll->insertAtTail(20);
  cdll->Print();
  cdll->insertAtTail(30);
  cdll->Print();
  cdll->insertAtTail(40);
  cdll->Print();
  cdll->insertAtTail(50);
  cdll->Print();
  cdll->insertAtTail(60);
  cdll->Print();
  cdll->insertAtTail(70);
  cdll->Print();
  cdll->insertAtTail(80);
  cdll->Print();
  cdll->deleteTail();
  cdll->Print();
  cdll->deleteTail();
  cdll->Print();
  cdll->deleteTail();
  cdll->Print();
  cdll->deleteHead();
  cdll->Print();
  cdll->deleteHead();
  cdll->Print();
  cdll->deleteHead();
  cdll->Print();
  cdll->PrintReverse();
  cdll->PrintHead();
  cdll->PrintTail();
  cdll->Print();
  cdll->insertAtLocation(100, 8);
  cdll->insertAtLocation(100, 1);
  cdll->Print();
  cdll->insertAtLocation(200, 8);
  cdll->Print();
  cdll->insertAtLocation(500, 0);
  cdll->insertAtLocation(1500, 5);
  cdll->Print();
  cdll->deleteAtLocation(5);
  cdll->Print();
  cdll->deleteAtLocation(1);
  cdll->Print();
  cdll->deleteAtLocation(9);
  cdll->deleteAtLocation(0);
}

/*
Functions Implemented
Insertion:
1)At head
2)At Tail
3)At entered location

Delete
1)At Tail
2)At Head
3)At entered location

Print:
1)Print Doubly Circular Linked List
2)Print Doubly Circular Linked List in Reverse
3)Print Head
4)Print Tail
*/