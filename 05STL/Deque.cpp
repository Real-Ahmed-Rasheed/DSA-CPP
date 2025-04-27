#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_front(2);
    d.push_back(1);
    // for(int i:d){
    //     cout<<i<<endl;
    // }
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    cout<< d.back()<<endl;
    cout<< d[0]<<endl;
}