#include <iostream>
using namespace std;
int peakIndex(int *arr, int e, int s = 0)
{
    int ans = -1;
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return -1;
    }
    if (s == e)
    {
        return s;
    }

    if (arr[mid] < arr[mid + 1])
    {
        return peakIndex(arr, e, mid + 1);
    }
    else
    {
        return peakIndex(arr, mid, s);
    }
}
int main()
{
    int arr[4] = {0, 1, 2, 0};
    int end = 4;
    int index = peakIndex(arr, end, 0);
    cout << " at index: " << index;
}