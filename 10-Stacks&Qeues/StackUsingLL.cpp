#include<iostream>
using namespace std;

class stackLL{
    private:
        class Node{
            public:
                int data;
                Node* next;
                Node(int d){
                    this->data = d;
                    this->next = NULL;
                }
        };
        Node* top;
        int size;
    public:
        stackLL(){
            top = NULL;
            size = 0;
        }
        void push(int n){
            if(top == NULL){
                Node* temp = new Node(n);
                top = temp;
                size++;
            }else{
                //insertion at head so we can pop using top
                Node* temp = new Node(n);
                temp->next = top;
                top = temp;
                size++;
            }
        }    
        void pop(){
            if(top == NULL){
                cout<<"Stack underflow"<<endl;
            }else{
                Node* temp = top;
                top = top->next;
                delete temp;
                size--;
            }
        }
        void peek(){
            if(top == NULL){
                cout<<"Stack underflow"<<endl;
            }else{
                cout<<"Top at: "<<top->data<<endl;
            }
        }
        void Size(){
            cout<<"Size is: "<<size<<endl;
        }
};

int main(){
    stackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.Size();
    s.peek();
    s.pop();
    s.peek();
    s.Size();
    return 1;
}