#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> s1;
    void push(int val) {
        if(s1.empty())
            s1.push({val,val});
        else
            s1.push({val,min(val,s1.top().second)});
    }
    void pop() {
        s1.pop();
    }
};

int main(){
    //T.C O(n) 
    //S.C O(2n)
    MinStack s;
    s.push(100);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<s.s1.top().second<<endl;
    return 1;
}