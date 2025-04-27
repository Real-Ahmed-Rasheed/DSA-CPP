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
void insertAtTail(Node* &tail, Node* temp){
    tail->next = temp;
    tail = temp;
}
Node* sortList(Node *head){
    //just changes pointer doesn't use extra space
    //TC: O(n) , SC: O(1)

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //setting up LL's
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            insertAtTail(zeroTail, temp);
        } else if(temp->data == 1){
            insertAtTail(oneTail, temp);
        } else{
            insertAtTail(twoTail, temp);
        }
        temp = temp->next;
    }

    //merging sub lists:
    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;

}
int main(){
    return 1;
}