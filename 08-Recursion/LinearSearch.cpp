#include<iostream>
using namespace std;

int linSearch(int* arr, int n, int k, int i=0){
    if(i==n)
        return -1;
    if(arr[i]==k)
        return i;
    return linSearch(arr, n, k, i+1);
    
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int k =3;
    int index = linSearch(arr, n, k); 
    cout<<"Found "<<k<<" at index: "<<index;
}