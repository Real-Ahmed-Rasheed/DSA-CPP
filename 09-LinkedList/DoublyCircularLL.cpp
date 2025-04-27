#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = this-> prev = this;
    }
    
    ~Node(){
        this->next = NULL;
        this->prev = NULL;
        cout<<"Deleted "<<this->data<<endl;
        this->data = 0;
    }
};
class doublyCircular{
    Node* head = NULL;
    Node* tail = NULL;
    public:
        doublyCircular(int data){
            Node* newNode = new Node(data);
            head = tail = newNode;
        }
        void insertNode(int data, int position){
            Node* newNode = new Node(data);
            if(position <= 1){
                newNode -> prev = tail;
                newNode -> next = head;
                tail -> next = newNode;
                head -> prev = newNode;
                tail = newNode;          
 
            } else{
                Node* temp = head;
                for (int i = 1; i < position-1; i++)
                {
                   temp = temp ->next;
                }
                newNode->next = temp->next;
                newNode->prev = temp->next->prev;
                temp->next = newNode;
                newNode->next->prev = newNode;
                if (temp == tail)
                {
                  tail = newNode;
                }
            }
        }
        void print(){
            Node* temp = head;
            do
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            } while (temp != head);

            //or use this 
            // while (temp != tail)
            // {
            //    cout<<temp->data<<" ";
            //     temp = temp->next;
            // }
            //    cout<<temp->data<<" ";
            
            // cout<<endl;
            
        }
        void getTailHead(){
            cout<<"Head: "<<head->data<<" - Tail: "<<tail->data<<endl;
        }
        void deleteNode(int position){
            if(position == 1){
                tail->next = head->next;
                head->next->prev = tail;
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            else if (head->next == head)
            {
                delete tail;
                tail = head = NULL;
            }
            else{
                Node* temp = head ->next;
                int i = 1;
                while (temp != head && i<position-1)
                {
                    temp = temp->next;
                    i++;
                }
                if(i<position-1){
                    cout<<"Invalid Position"<<endl;
                    return;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
                
            }
        }
};
int main(){
    doublyCircular d(1);
    d.insertNode(2,2);
    d.insertNode(3,3);
    d.insertNode(4,4);
    d.insertNode(5,5);
    d.insertNode(33,3);
    d.getTailHead();
    d.print();
    d.deleteNode(1);
    d.print();
    d.deleteNode(2);
    d.print();
    d.getTailHead();
    return 0;
}