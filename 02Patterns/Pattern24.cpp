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
        int value=i;
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
       


       cout<<endl;
       i++;
    }

    return 0;
}
