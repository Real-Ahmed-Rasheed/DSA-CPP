#include <iostream>
#include <vector>
using namespace std;
void helper(string &s, int st, int e)
{
    while (st <= e)
    {
        swap(s[st++], s[e--]);
    }
}
string reverseWords(string s)
{

    int n = s.size();
    int st = 0, end = n - 1;
    while (st <= end)
    {
        swap(s[st++], s[end--]);
    }
    st = 0;
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || i == s.length())
        {
            helper(s, st, i - 1);
            st = i + 1;
        }
    }

    return s;
}
int main()
{
    string s;
    cout << "Enter String:" << endl;
    getline(cin, s);
    cout << "Output: " << reverseWords(s) << endl;
    // pharase like "the bus is blue"
}