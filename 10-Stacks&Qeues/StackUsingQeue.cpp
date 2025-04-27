#include<iostream>
#include<queue>
using namespace std;

class customStack{
    private:
        queue<int> q1;
        int size = 0;
    public:
        void push(int n){
            q1.push(n);
            size = q1.size();
            for (int i = 1; i < size; i++)
            {
                q1.push(q1.front());
                q1.pop();
                
            }
        }    
        void pop(){
            q1.pop();
        }
        void peek(){
            cout<<"Top at: "<<q1.front()<<endl;
        }
        void Size(){
            cout<<"Size: "<<q1.size()<<endl;
        }
        void print(){
            queue <int> q2 = q1;
            while(!q2.empty()){
                cout<<q2.front()<<" ";
                q2.pop();
            }
            cout<<endl;
        }
};


int main(){
    customStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.peek();
    s.pop();
    s.peek();
    return 0;
}