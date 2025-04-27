#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        // 1st number triangle
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << j;
            j++;
        }

        // 1st star triangle
        int stars = i - 1;
        while (stars)
        {
            cout << "*";
            stars--;
        }

        // 2nd star triangle
        int stars2 = i - 1;
        while (stars2)
        {
            cout << "*";
            stars2--;
        }

        // 2nd number triangle
        int j2 = n- i+ 1;
        while (j2)
        {
            cout<<j2;
            j2--;
        }
        

        cout<< endl;
        i++;
    }
}