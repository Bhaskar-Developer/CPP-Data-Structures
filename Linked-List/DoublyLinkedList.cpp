#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedList
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
    while (temp != nullptr)
    {
      count++;
      temp = temp->next;
    }
    return count;
  }

public:
  DoublyLinkedList()
      : head{nullptr}, tail{nullptr} {}

  void Print()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "DLL: Empty" << '\n';
      return;
    }

    Node *temp = this->head;
    cout << "DLL: ";
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << '\n';
  }

  void PrintReverse()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "DLL: Empty" << '\n';
      return;
    }

    Node *temp = this->tail;
    cout << "Reversed DLL: ";
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->prev;
    }
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
    this->head->prev = temp;
    this->head = temp;
  }

  void insertAtTail(const int value)
  {
    if (head == nullptr && tail == nullptr)
    {
      Node *temp = new Node(value);
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
    this->tail->next = temp;
    temp->prev = this->tail;
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
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
    node->next = next;
  }

  void deleteHead()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "DLL: Empty" << '\n';
      return;
    }
    Node *temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    this->head->prev = nullptr;
    delete (temp);
  }

  void deleteTail()
  {
    if (head == nullptr && tail == nullptr)
    {
      cout << "DLL: Empty" << '\n';
      return;
    }
    Node *previous = this->head;
    while (previous->next != tail)
    {
      previous = previous->next;
    }
    Node *temp = previous->next;
    this->tail = previous;
    temp->prev = nullptr;
    previous->next = nullptr;
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
    current->next = nullptr;
    current->prev = nullptr;
    delete (current);
  }

  ~DoublyLinkedList()
  {
    delete (head);
    delete (tail);
  }
};

int main()
{
  auto dll = make_unique<DoublyLinkedList>();

  dll->insertAtHead(10);
  dll->Print();
  dll->insertAtHead(20);
  dll->Print();
  dll->insertAtHead(30);
  dll->Print();
  dll->insertAtTail(40);
  dll->Print();
  dll->insertAtTail(50);
  dll->Print();
  dll->insertAtTail(60);
  dll->Print();
  dll->insertAtTail(70);
  dll->Print();
  dll->PrintReverse();
  dll->PrintHead();
  dll->PrintTail();
  dll->insertAtLocation(100, 3);
  dll->Print();
  dll->insertAtLocation(200, 5);
  dll->Print();
  dll->insertAtLocation(500, 20);
  dll->insertAtLocation(600, 0);
  dll->insertAtLocation(700, 10);
  dll->insertAtLocation(800, 9);
  dll->Print();
  dll->deleteHead();
  dll->Print();
  dll->deleteHead();
  dll->Print();
  dll->deleteTail();
  dll->Print();
  dll->deleteTail();
  dll->Print();
  dll->deleteAtLocation(3);
  dll->Print();
  dll->deleteAtLocation(1);
  dll->Print();
  dll->deleteAtLocation(0);
  dll->deleteAtLocation(10);
  dll->PrintReverse();
}

/*
Functions Implemented:
Insertion
1)At head
2)At tail
3)At entered location

Deletion
1)At head
2)At tail
3)At entered location

Print
1)Print Doubly Linked List
2)Print Doubly Linked List in Reverse order
3)Print Head
4)Print Tail
*/