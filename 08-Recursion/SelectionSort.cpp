#include<iostream>
using namespace std;
void sort(int *arr, int n, int i = 0) {
    if (i == n) {
        return;
    }

    int minI = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minI]) {
            minI = j;
        }

    }

    swap(arr[i], arr[minI]);
    sort(arr, n, i + 1);
}
int main(){
    int arr[6] = {2,1,5,1,88,0};
    int n =6;
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}