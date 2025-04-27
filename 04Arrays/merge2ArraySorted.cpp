#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr1[], int n, int arr2[], int m, int sorted[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            sorted[k++] = arr1[i++];
        }
        else
        {
            sorted[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        sorted[k++] = arr1[i++];
    }
    while (j < m)
    {
        sorted[k++] = arr2[j++];
    }
}
int main()
{
    int even[5] = {2, 4, 6, 8, 10};
    int odd[5] = {1, 3, 5, 7, 9};
    int n = 5;
    int m = 5;
    int sorted[10];
    merge(even, n, odd, m, sorted);
    printArray(sorted, 10);
}