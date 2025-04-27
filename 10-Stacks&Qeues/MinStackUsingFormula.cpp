#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MinStack
{
public:
    stack<int> s1;
    int min;
    void push(int val)
    {
         if(s1.empty()){
            min = val;
            s1.push(val);
         } else{
            //stack not empty
            if(val < min){
                s1.push(2*val - min);
                min = val;
            } else{
                s1.push(val);
            }
         }
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int x = s1.top();
        s1.pop();
        if (x < min)
        {
            min = 2 * min - x;
        }
    }
    void top()
    {
        if (s1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        if (s1.top() < min)
            cout << min << endl;
        else
            cout << s1.top() << endl;
    }
    void getMin()
    {
        cout << "Min: " << min << endl;
    }
    void print() {
        stack<int> temp = s1; // Create a temporary stack to print
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    MinStack s;
    s.push(100);
    s.push(-2);
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(4);
    s.getMin();
    s.print();
    return 1;
    /*
    input:
    100 -2 3 5 6 7 8 4
    stack
    100 -104 3 5 6 7 8 4
    min
    100/ -2



    Formula:
    2*valueJiskoConvertKarnaHa - (valueJismeConvertKarnaHa)
    */
}