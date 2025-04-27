
#include<iostream>
#include<stack>
#include <limits.h>
using namespace std;

int main(){
    int arr[4] = {1,2,3,0};
    int n = 4;

    int nge[n];
    fill_n(nge, n, -1);
    stack<int> s;
    for (int i = n-1; i>=0; i--)
    {
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        if(!s.empty()){
            nge[i] = s.top();
        }
        s.push(arr[i]);
    }

    //if we solve by iterating forward
    //storing indeces in stack    
    // for (int i = 0; i<n; i++)
    // {
    //     while (!s.empty() && arr[s.top()] < arr[i]) {
    //         nge[s.top()] = arr[i]; // Assign the next greater element
    //         s.pop();
    //     }
    //     s.push(i);

    // }

    for (int i = 0; i < n; i++)
    {
        cout<<nge[i]<<" ";
    }
    cout<<endl;
    return 0;
}