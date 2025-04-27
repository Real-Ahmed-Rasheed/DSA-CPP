#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr1[4] = {1,2,3,44};
    int arr2[4] = {2,2,32,44};
    int i =0;
    int j=0;
    vector<int> ans;
    //provided that both arrays are in sorted order
    while(i<4 && j<4){
        if(arr1[i] == arr2[j]){
            if(ans.size() == 0 || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}