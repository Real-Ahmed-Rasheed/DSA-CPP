#include <iostream>
using namespace std;
void merge(int *arr, int s, int e, int mid)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    cout<<"len1: "<<len1<<"   ";
    cout<<"len2: "<<len2<<"   ";
    cout<<"s: "<<s<<"   ";
    cout<<"m: "<<mid<<"   ";
    cout<<"e: "<<e<<endl;

    int *first = new int[len1];
    int *second = new int[len2];
    int mPtr = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mPtr++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mPtr++];
    }
    mPtr = s;
    int i1 = 0;
    int i2 = 0;
    while (i1 < len1 && i2 < len2)
    {
        if (first[i1] < second[i2])
        {
            arr[mPtr++] = first[i1++];
        }
        else
        {
            arr[mPtr++] = second[i2++];
        }
    }

    while (i1 < len1)
    {
        arr[mPtr++] = first[i1++];
    }
    while (i2 < len2)
    {
        arr[mPtr++] = second[i2++];
    }
    delete []first;
    delete []second;
}
void sort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    // left part:
    sort(arr, s, mid);
    sort(arr, mid + 1, e);

    merge(arr, s, e, mid);
}

int main()
{
    int arr[4] = {8,2,9,1};
    int n = 4;
    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
