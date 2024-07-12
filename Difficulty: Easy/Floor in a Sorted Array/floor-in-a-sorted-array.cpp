//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
int findFloor(vector<long long> v, long long n, long long x) {
    long long l = 0, h = n - 1, m;
    long long floorIndex = -1; // Initialize the floor index to -1 (indicating no valid floor found yet)

    while (l <= h) {
        m = l + (h - l) / 2;
        if (v[m] <= x) {
            floorIndex = m; // Update the floor index
            l = m + 1; // Continue to search in the right half
        } else {
            h = m - 1; // Continue to search in the left half
        }
    }

    return floorIndex;
}
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends