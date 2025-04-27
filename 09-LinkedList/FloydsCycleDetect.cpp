#include<iostream>
/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
Node* floydDetect(Node* &head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow!= NULL && fast!=NULL && fast->next != NULL){
        fast= fast->next->next;
        slow =slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;

}
Node* startOfLoop(Node* &head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* meetingPoint = floydDetect(head);
    if (meetingPoint == NULL) {
        return NULL;
    }

    while(slow != meetingPoint){
        meetingPoint = meetingPoint->next;
        slow = slow->next;
    }
    return slow;
}
void delLoop(Node* &head){
    Node* startLoop = startOfLoop(head);
    if(startLoop ==NULL){
        return;
    }
    Node* temp = startLoop;

    while(temp->next != startLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}
Node *removeLoop(Node *head)
{
   delLoop(head);
   return head;
}