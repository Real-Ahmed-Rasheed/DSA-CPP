#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
int main(){
    
    Node* n1 = new Node(1);
    Node* n2 = new Node(12);
    n1->right = n2;

}