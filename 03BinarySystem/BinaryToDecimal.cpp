#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<"Enter Binary:";
    int n;
    cin>>n;
    int ans=0;
    int i=0; 
    while(n!=0){
        int digit=n%10;
        if(digit==1){
            ans=ans+ n << i;
        }
        n=n/10;
        i++;
    }
    cout<<"Decimal:"<<ans;
}
