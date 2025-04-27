#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;

    int num=1;
    int i =1;
    while (i<=n){   
       int j = 1;
       while (j<=n)
       {
        cout<<num<<" ";
        num++;
        j++;
       }
       cout<<endl;
       i++;
    }
    

    return 0;
}
