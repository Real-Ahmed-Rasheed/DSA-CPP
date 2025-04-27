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

void sort012(int arr[], int n)
{
    int j = 0;
    int k = n - 1;

    for (int i = 0; j < k;)
    {
        if (arr[j] == 0)
        {
            swap(arr[j], arr[i]);
            i++;
            j++;
        }
        else if (arr[j] == 2)
        {
            swap(arr[j], arr[k]);
            k--;
        }
        else
        {
            // case for 1
            j++;
        }
    }
}
int main()
{

    int arr[6] = {1, 2, 0, 1, 0, 2};
    int size = 6;
    printArray(arr, size);
    sort012(arr, size);
    printArray(arr, size);
    return 1;
}