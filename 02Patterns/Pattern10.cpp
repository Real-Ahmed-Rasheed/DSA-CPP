#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int value = 1;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            char ch = 'A' + value - 1;
            cout << ch << " ";
            value++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
