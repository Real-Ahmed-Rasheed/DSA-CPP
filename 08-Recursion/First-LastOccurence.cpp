#include <iostream>
using namespace std;

int firstOcc(int *arr, int k, int e, int s = 0)
{
    int ans = -1;
    int mid = s + (e - s) / 2;

    if (s > e)
        return -1;
    if (arr[mid] == k)
    {
        ans = firstOcc(arr, k, mid - 1, s);
        return (ans == -1) ? mid : ans;
    }

    if (arr[mid] > k)
    {
        return firstOcc(arr, k, mid - 1, s);
    }
    else if (arr[mid] < k)
    {
        return firstOcc(arr, k, e, mid + 1);
    }
}
int lastOcc(int *arr, int k, int e, int s = 0)
{
    int ans = -1;
    int mid = s + (e - s) / 2;

    if (s > e)
        return -1;
    if (arr[mid] == k)
    {
        ans = lastOcc(arr, k, e, mid+1);
        return (ans == -1) ? mid : ans;
    }

    if (arr[mid] > k)
    {
        return lastOcc(arr, k, mid - 1, s);
    }
    else if (arr[mid] < k)
    {
        return lastOcc(arr, k, e, mid + 1);
    }
}
int main()
{
    int arr[5] = {1, 1 , 3, 4, 5};
    int end = 5;
    int key = 1;
    int index = lastOcc(arr, key, end, 0);
    cout << "Found " << key << " at index: " << index;
}