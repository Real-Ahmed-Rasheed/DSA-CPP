#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;

    long long ans = 0; 
    int bit;
    
    for (int i = 0; i < 32; i++) {
        bit = (n >> i) & 1; //for getting the ith bit and right shifting on each iteration
        bit = ~bit & 1; // for negating the last bit
        ans = ans|(bit << i); // OR(|) to only consider 1's and this expression equuals to ans+2^i
    }

   
    cout << "The two's complement (negative binary) is: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((ans >> i) & 1); 
    }
    cout << endl;
    cout << ans;

    return 0;
}
