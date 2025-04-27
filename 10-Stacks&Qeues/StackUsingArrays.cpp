#include<iostream>
using namespace std;

class stack{
    private:
     int size;
     int* arr;
     int top;
    public:
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }   

    void push(int n){
        if(top < size-1){
            top++;
            arr[top] = n;
        }else{
            cout<<"Stack overflow"<<endl;
        }   
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
        } else{
            top--;
        }
    }
    void peek(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
        } else{
            cout<<arr[top]<<endl;
        }
    }
    void Size(){
        cout<<size<<endl;
    }
};

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(8);
    s.peek();
    s.Size();
    return 1;
}