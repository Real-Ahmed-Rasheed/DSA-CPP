#include<iostream>  
using namespace std;
void leftRotate(int arr[], int size){
    int temp = arr[0];
    //shift left by 1
    for(int i=1; i<size; i++){
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int n =5;
    printArray(arr, n);
    leftRotate(arr, n);
    printArray(arr, n);

}