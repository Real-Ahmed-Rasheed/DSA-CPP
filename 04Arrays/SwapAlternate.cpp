#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{
    //     int start = 0;
    //     int end =1;
    //    while (end<=size)
    //    {
    //     swap(arr[start], arr[end]);
    //     start+=2;
    //     end+=2;
    //    }

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            // swaping using inBuiltFuntion
            //  swap(arr[i], arr[i+1]);

            // swaping using third variable
            //  int temp = arr[i];
            //  arr[i] = arr[i+1];
            //  arr[i+1] = temp;

            // swaping using arithmrtic operations
            //  arr[i] = arr[i]+ arr[i+1];
            //  arr[i+1]= arr[i] - arr[i+1];
            //  arr[i] = arr[i] - arr[i+1];

            // swaping using XOR
            arr[i] = arr[i] ^ arr[i + 1];
            arr[i + 1] = arr[i] ^ arr[i + 1];
            arr[i] = arr[i] ^ arr[i + 1];
        }
    }
}
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
    int arr[100];
    int size;
    cout << "Enter Size: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    swapAlternate(arr, size);
    printArray(arr, size);

    return 0;
}