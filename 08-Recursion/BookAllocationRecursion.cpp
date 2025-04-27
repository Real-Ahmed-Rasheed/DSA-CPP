#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> &time, long long mid, long long int Ndays, long long int Mchapters)
{
    long long int DayCount = 1;
    long long int Chapters = 0;

    for (int i = 0; i < Mchapters; i++)
    {
        if (Chapters + time[i] <= mid)
        {
            Chapters += time[i];
        }
        else
        {
            DayCount++;
            if (DayCount > Ndays || time[i] > mid)
            {
                return false;
            }
            Chapters = time[i];
        }
    }
    return true;
}
int binarySearchRecursion(vector<int> &time, int start, int end, int m, int n)
{
    long long mid = start + (end - start) / 2;
    if (start > end)
        return start;
    


    if (isValid(time, mid, n, m))
    {
        return binarySearchRecursion(time, start, mid - 1, m, n);
    }
    else
    {
        return binarySearchRecursion(time, mid + 1, end, m, n);
    }
}
int ayushGivesNinjatest(long long int Ndays, long long int Mchapters, vector<int> &time)
{
        // //setting SearchSpace:
        long long start = 0;
        long long end;
        for (int i = 0; i < Mchapters; i++)
        {
            end += time[i];
        }
        long long mid = start + (end - start) / 2;
        return binarySearchRecursion(time, start, end, Mchapters, Ndays);
}

int main()
{
    int m = 5;
    int n = 3;
    vector<int> time = {1, 2, 2, 3, 1};

    int result = ayushGivesNinjatest(n, m, time);
    cout << "Minimum Maximum Study Time: " << result << endl;
}