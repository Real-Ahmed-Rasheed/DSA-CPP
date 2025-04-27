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

int upperPivot(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s)/2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return s;
}
int main()
{
    int odd[6] = {4,5, 44, 1,2,3};
    printArray(odd , 6);
    int pivt = upperPivot(odd, 6);
    cout<<"The pivot is: "<<odd[pivt];

    return 0;
}