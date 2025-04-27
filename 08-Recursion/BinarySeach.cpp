#include <iostream>
using namespace std;
void printArray(int *arr, int s, int k){

    for (int i = s; i < k; i++)
    {
        cout<<arr[i]<< " ";
    } cout<<endl;
}
int binarySearch(int *arr, int k, int e, int s = 0)
{   printArray(arr, s, e);
    int mid = s + (e - s) / 2;
    if (s > e)
        return -1;
    if (arr[mid] == k)
        return mid;

    if (arr[mid] > k)
    {
        return binarySearch(arr, k, mid-1, s);
    }
    else if(arr[mid] < k)
    {
        return binarySearch(arr, k, e, mid+1);
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int end = 5;
    int key = 5;
    int index = binarySearch(arr, key, end, 0);
    cout << "Found " << key << " at index: " << index;
}