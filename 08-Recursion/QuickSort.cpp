#include <iostream>
using namespace std;
int sort(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = 0; i < e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }
    // place at right index
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        
        swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = sort(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[4] = {8, 2, 9, 1};
    int n = 4;
    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
