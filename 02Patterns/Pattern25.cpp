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
        int value=1;
        int j =1;

       //spaces
       int spaces = n-i;
       while (spaces)
       {
        cout<<" ";
        spaces--;
       }
       
       while (j<=i)
       {
        cout<<value;
        value++;
        j++;
       }
       
       int start = i-1;
        while (start)
        {
            cout<<start;
            start--;
        }
        

       cout<<endl;
       i++;
    }

    return 0;
}
