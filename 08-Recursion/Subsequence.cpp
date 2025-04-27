#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void printSubsequence(vector<int> arr, int n, vector<int> subSeq, int index=0)
{
    if (index == n)
    {
        if (subSeq.size() == 0)
        {
            cout << "{}" << " ";
        }
        for (auto it : subSeq)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // not include
    printSubsequence(arr, n, subSeq, index + 1);
    // include11
    subSeq.push_back(arr[index]);
    printSubsequence(arr, n, subSeq, index + 1);
    /*
    {}
    2
    1
    1 2
    3
    3 2
    3 1
    3 1 2
    */
}
int main()
{
    vector<int> arr = {3, 1, 2};
    int n = 3;
    sort(arr.begin(),arr.end());
    vector<int> subSeq;
    printSubsequence(arr, n, subSeq);
}