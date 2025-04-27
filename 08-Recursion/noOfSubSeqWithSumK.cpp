#include <iostream>
#include <vector>
using namespace std;
int noOfSubSeqwithSumK(int arr[], int n, int RequiredSum, int sumStore, int index =0)
{
    if (index == n)
    {
        if (sumStore == RequiredSum)
            return 1;
        else    
            return 0;
    }
    int count = 0;

    // not include
    count += noOfSubSeqwithSumK(arr, n, RequiredSum, sumStore, index + 1);

    //include
    sumStore += arr[index];
    count += noOfSubSeqwithSumK(arr, n, RequiredSum, sumStore, index + 1);
    return count;
}
int main()
{
    int arr[3] = {1, 2, 1};
    int n = 3;
    int sum = 4;
    cout << noOfSubSeqwithSumK(arr, n, sum, 0)<<endl;

    //T.C: 2^n
    //S.C: N
}