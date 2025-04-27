#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        cout << "Node with data " << this->data << " is being deleted\n";
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtMiddle(Node *&head, int position, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    // inserting at start
    if (position == 0)
    {
        insertAtHead(head, data);
        return;
    }
    // inserting at end
    if (temp->next == NULL)
    {
        insertAtEnd(head, data);
        return;
    }

    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(Node *&head, int position)
{
    Node *prev = NULL;
    Node *current = head;
    for (int i = 1; i < position; i++)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
}
void print(Node *head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node *n1 = new Node(10);
    Node *head = n1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtEnd(head, 90);
    cout << "Before: ";
    print(head);
    insertAtMiddle(head, 4, 9999);
    cout << "After: ";
    print(head);
    cout << "Head is at: " << head->data << endl;
    deleteNode(head, 2);
    print(head);
    return 0;
}