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
        cout << "Deleted " << this->data << endl;
    }
};
class CircularLL
{
private:
    Node *tail = NULL;

public:
    CircularLL(int d)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }

    void insert(int elementToInsert, int afterElement)
    {
        Node *newNode = new Node(elementToInsert);
        if (tail == NULL)
        {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        else
        {
            Node *curr = tail;
            while (curr->data != afterElement)
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            if (curr == tail)
            {
                tail = newNode; // agar tail curr par ha tu new par karde
            }
        }
    }
    void deleteNode(int element)
    {
        Node *prev = tail;
        Node *curr = prev->next;
        if (curr == tail && curr->data == element)
        {
            delete curr;
            tail = NULL; // List is now empty
            return;
        }
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        // update tail to prev as we are deleting current node
        if (curr == tail)
        {
            tail = prev;
        }
        delete curr;
    }
    void print()
    {
        if (tail == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = tail->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << " Tail: " << tail->data << endl;
    }
};
int main()
{
    CircularLL c1(10);
    c1.insert(20, 10);
    c1.insert(30, 20);
    c1.insert(40, 30);
    c1.insert(22, 20);
    c1.insert(23, 22);
    c1.insert(0, 10);
    // c1.print();
    // c1.deleteNode(40);
    // c1.deleteNode(0);
    // c1.deleteNode(20);
    // c1.deleteNode(22);
    // c1.deleteNode(23);
    // c1.deleteNode(30);
    // c1.deleteNode(10);
    c1.print();
    return 0;
}