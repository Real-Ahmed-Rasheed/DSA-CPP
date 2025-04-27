#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int value = this->data;
        this->next = NULL;
        this->prev = NULL;
        cout<<"Deleted "<<value<<endl;
    }
};
class DoublyLL
{
private:
    Node *head = NULL;

public:
    DoublyLL(int d)
    {
        head = new Node(d);
    }

    void insert(int position, int data)
    {
        Node *temp = this->head;
        Node *newNode = new Node(data);
        // at starting
        if (position <= 1)
        {
            newNode->next = this -> head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        int i = 1;
        while (i < position - 1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        // ending position
        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
        }
        else
        {
            // insertion at middle
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    void print()
    {
        Node *temp = this->head;
        if(temp == NULL){
            cout<<"Empty List"<<endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
        cout<<"~Head at: "<< head->data<<endl;
    }
    void deleteNode(int position){
        Node* curr = this->head;
        Node* prevNode = NULL;
        //starting
        if (position <= 1) {
            head = head->next;
            if (head != NULL) head->prev = NULL;
            curr->next = NULL;
            delete curr;
            return;
        }
        int i = 1;
        while ( i<position && curr->next != NULL)
        {
           prevNode = curr;
           curr = curr->next;
           i++;
        }
        if (i < position) {
            cout << "Position exceeds list size. Nothing to delete." << endl;
            return;
        }
        prevNode->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = prevNode;
        }
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
};
int main()
{
    DoublyLL d(10);
    d.insert(2, 20);
    d.insert(3, 30);
    d.insert(4, 40);  // Insert at position 4, which is beyond current size
    d.print();  // Output: 20 10 30 40
    d.deleteNode(1);
    d.deleteNode(1);
    d.deleteNode(1);
    d.deleteNode(1);
    d.print();
    return 0;
}