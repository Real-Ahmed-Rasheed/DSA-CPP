#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int row = 1;
    while (row <= n)
    {

        int spaces = n - row;
        while (spaces)
        {
            cout << " ";
            spaces--;
        }

        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col++;
        }

        cout << endl;
        row++;
    }
    return 0;
}
