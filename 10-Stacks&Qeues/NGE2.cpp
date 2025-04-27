
#include<iostream>
#include<stack>
#include <limits.h>
using namespace std;
 
 //circular NGE
int* NGE(int arr[], int n) {
    int* nge = new int[n];
    fill_n(nge, n, -1);
    stack<int> s;
    for (int i = 2*n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i%n]) {
            s.pop();
        }
        if (!s.empty()) {
            nge[i%n] = s.top();
        }
        s.push(arr[i%n]);
    }
    return nge;
}

int main(){
    int arr[5] = {1,3,11,6,10};
    int n = 5;
    int* nge = NGE(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<*(nge+i)<<" ";
    }
    cout<<endl;
    
    return 1;
}
