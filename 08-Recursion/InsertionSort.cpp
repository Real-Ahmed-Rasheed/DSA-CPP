#include <iostream>
using namespace std;
void sort(int *arr, int n, int i = 1)
{
    if (i == n)
    {
        return;
    }
    sort(arr, n, i + 1);
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        arr[temp] = arr[j];
        j--;
    }
}
    int main()
    {
        int arr[6] = {2, 1, 5, 1, 88, 0};
        int n = 6;
        sort(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        return 0;
    }