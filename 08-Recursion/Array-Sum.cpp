#include<iostream>
using namespace std;

int getSum(int* arr, int n){
    if(n==1)
        return arr[0];
    if(n==0)    
        return 0;
        
    int remainingPart = getSum(arr+1, n-1);
    int sum = arr[0] + remainingPart;
    return sum;
    
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int sum = getSum(arr, n); 
    cout<<sum;
}