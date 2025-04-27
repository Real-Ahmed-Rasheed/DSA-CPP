#include <iostream>
#include <vector>
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
void insert(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    Node *temp = tail;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    tail = newNode;
}
void print(Node *tail){
    Node* temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while (tail != temp);
    cout<< endl;
}
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
vector<Node*> splitList(Node* head){
    vector<Node*> v;
    Node* mid = getMid(head);
    Node* h2 = mid->next;

    Node* temp = head;
    while(temp != mid){
        temp = temp->next;
    }
    temp->next = head;
    temp = h2;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = h2;


    v.push_back(head);
    v.push_back(h2);
    return v;
}
int main()
{
    //divides one circular LL into 2
    Node *n1 = new Node(1);
    Node *tail = n1;
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    insert(tail, 6);
    tail->next = n1;
    print(tail);
    vector<Node*> ans;
    ans = splitList(n1);
    
    
    cout<<"First head at: "<<ans[0]->data<<endl;
    cout<<"Second head at: "<<ans[1]->data<<endl;
    print(ans[0]);
    print(ans[1]);

    // print(tail);
    // cout << "Tail is at: " << tail->data << endl;
    //ahmed
    return 0;
}
