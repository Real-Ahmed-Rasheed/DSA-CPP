#include <iostream>
#include <vector>
using namespace std;
bool isPossibe(vector<int> &boards, int mid, int n, int k)
{
    int paintersCount = 1;
    int boardsSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (boardsSum + boards[i] <= mid)
        {
            boardsSum += boards[i];
        }
        else
        {
            paintersCount++;
            if (paintersCount > k || boards[i] > mid)
            {
                return false;
            }
            boardsSum = boards[i];
        }
    }
    return true;
}
int binarySearchRecursion()
{
}
int main()
{

    int s = 1;
    int sum = 0;
    int n = boards.size();
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int result = -1;

    while (s <= e)
    {
        if (isPossibe(boards, mid, n, k))
        {
            result = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return result;
    int m = 5;
    int n = 3;
    vector<int> time = {1, 2, 2, 3, 1};

    int result = ayushGivesNinjatest(n, m, time);
    cout << "Minimum Maximum Study Time: " << result << endl;
}