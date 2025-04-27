#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <char> s = {'h', 'e', 'l', 'l', 'o'};
    int n = s.size();
    int st = 0, e = n;
    while (st <= e)
    {
        swap(s[st++], s[e--]);
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<s[i];
    }
    cout<<endl<<n;
    }