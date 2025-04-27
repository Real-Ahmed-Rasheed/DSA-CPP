#include <iostream>
using namespace std;

void swapPointer(int*, int*);

int main(int argc, char const *argv[])
{
    int a = 10 ,b= 20; 
    swapPointer(&a ,&b);
   cout<< "The value of a is :"<< a <<" and b is: "<<b<<endl;
    return 0;
}

void swapPointer(int* x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}