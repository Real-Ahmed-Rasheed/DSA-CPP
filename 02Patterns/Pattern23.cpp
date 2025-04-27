#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
       int spaces = i-1;
        while (spaces)
        {
            cout << "-";
            spaces--;
        }

        int j = i;
        while (j <= n)
        {
            cout << j;
            j++;
        }
        
        cout << endl;
        i++;
    }
    return 0;
}
