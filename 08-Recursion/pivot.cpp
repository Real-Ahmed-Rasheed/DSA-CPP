#include <iostream>
using namespace std;
int lowerPivot(int *arr, int e, int s = 0)
{
    int mid = s + (e - s) / 2;
    if (s == e)
    {
        return s;
    }

    if (arr[mid] >= arr[0])
    {
        return lowerPivot(arr, e, mid + 1);
    }
    else
    {
        return lowerPivot(arr, mid, s);
    }
}
int upperPivot(int *arr, int e, int s = 0){
    int mid = s + (e-s)/2;
    //base case
    if (s==e)
        return s;
    
     if (arr[mid] > arr[mid + 1]) {
        return mid;
    }
    if (arr[mid] < arr[mid - 1]) {
        return mid - 1;
    }

    if (arr[mid] >= arr[s]) {
        return upperPivot(arr, e, mid + 1);
    } else {
        return upperPivot(arr, mid - 1, s);
    }
}
int main()
{
    int arr[5] = {7,9,10,2,4};
    int end = 5;
    int index = upperPivot(arr, end);
    cout << " at index: " << index;
}