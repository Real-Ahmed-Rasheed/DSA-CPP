#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void generateSubarrays(vector<int>& arr, int n, vector<int>& current, vector<vector<int>>& result, int index) {

    // Base case: subarray of size 3 found
    if (current.size() == 3) {
        result.push_back(current);
        return;
    }

    // Termination condition
    if (index >= n) {
        return;
    }

    // Add current element to subarray
    current.push_back(arr[index]);

    // Continue generating subarrays
    generateSubarrays(arr, n, current, result, index + 1);

    // Backtrack
    current.pop_back();
}

// Wrapper function to generate all subarrays of size 3
vector<vector<int>> findSubarrays(vector<int>& arr) {

    vector<vector<int>> result;

    // Try starting subarrays from different positions
    for (int i = 0; i <= arr.size(); i++) {
        vector<int> current;
        generateSubarrays(arr, arr.size(), current, result, i);
    }

    return result;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4,5,6,7,8,9};
    vector<vector<int>> ans = findSubarrays(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}