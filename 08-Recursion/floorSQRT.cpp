#include <iostream>
#include <cmath>
using namespace std;

int floorSQRT(int n, int s = 1, int end = -1){
    if(end == -1) end = sqrt(n);
    
    int mid = s+(end-s)/2;
    //base case:
    if(s>end){
        return end;
    }

    if(mid*mid == n) return mid;
    if(mid*mid > n) {
        return floorSQRT(n, s, mid-1);
        }
    if(mid*mid < n){
        return floorSQRT(n, mid+1, end);
    }

}
int main()
{
    int n;
    cin >> n;
    cout << " Output: " << floorSQRT(n);
}