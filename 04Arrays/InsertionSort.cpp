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
int main()
{
    int arr[10] = {2, 4, 63, 66, 63, 8, 9, 11, 3, 5};
    printArray(arr, 10);
    int n = 10;

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            else
                break;
        }
    }
    printArray(arr, 10);

}