
//  * Definition for linked list.
  class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 

Node* merge(Node* a, Node* b) {

    // Base cases
    if (!a) return b;
    if (!b) return a;
    Node* result;

    // Choose either a or b, and recur

    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);

    } else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = nullptr; // Set next to nullptr for the flattened list
    return result;

}

Node* flattenLinkedList(Node* head) 
{
	if(head == nullptr)
		return nullptr;
	Node* down = head;
	Node* right = head->next;
	down->next = nullptr;
	right = flattenLinkedList(right);
	return merge(down, right);

}
