#include <iostream>
using namespace std;

class Queue
{
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
    };
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
public:
    void push(int data)
    {
        Node *newNode = new Node(data);
        size++;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void print(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void peek(){
        cout<<"Top: "<<head->data<<endl;
    }
    void Size(){
        cout<<"Size: "<<size<<endl;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.peek();
    q.Size();
    
    return 0;
}