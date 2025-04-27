#include<iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[10]= {2,4,63,66,63,8,9,11,3,5};
    printArray(arr,10);
    int n = 10;
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]) min = j;
        }
        swap(arr[min],arr[i]);
    }
    printArray(arr,10);

    
}