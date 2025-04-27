#include<iostream>
#include<stack>
using namespace std;

class sQueue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int n){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(n);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        void peek(){
            cout<<"Top at: "<<s1.top()<<endl;
        }
        void print(){
            stack <int> q2 = s1;
            while(!q2.empty()){
                cout<<q2.top()<<" ";
                q2.pop();
            }
            cout<<endl;
        }
        void size(){
            cout<<"Size: "<<s1.size()<<endl;
        }
        void pop(){
            s1.pop();
        }
};

int main()
{
    sQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    q.peek();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.peek();
    q.size();
    return 0;
}