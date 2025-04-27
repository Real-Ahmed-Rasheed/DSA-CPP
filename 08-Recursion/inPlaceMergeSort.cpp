#include <iostream>
using namespace std;
void merge(int *arr, int s, int e, int mid)
{
    int i = s;
    //mid is used for calculating starting of second array
    int j = mid + 1;

    cout << "i: " << i << "   ";
    cout << "j: " << j << "   ";
    cout << "s: " << s << "   ";
    cout << "m: " << mid << "   ";
    cout << "e: " << e << endl;
    //for visulization
    for (int i = 0; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            i++;
        }
        else
        {
            //i is greater than (or equal to) j
            int temp = arr[j];
            int index = j;
            //j should not go behind or on i's position
            while (index > i)
            {
                //right shifting all elements
                arr[index] = arr[index - 1];
                index--;
            }
            //placing j which was smaller at i
            arr[i] = temp;
            i++;
            j++;
        }
    }
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
    int arr[4] = {8, 2, 9, 1};
    int n = 4;
    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
