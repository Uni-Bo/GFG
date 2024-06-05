//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum_a = std::accumulate(a, a + n, 0);
        int sum_b = std::accumulate(b, b + m, 0);
        
        // The difference must be even to balance the sums
        int diff = sum_a - sum_b;
        if (diff % 2 != 0) {
            return -1;
        }
        
        int target = diff / 2;
        
        // Store elements of array 'a' in a set
        std::unordered_set<int> set_a(a, a + n);
        
        // Check each element in array 'b' if there's a corresponding element in 'a'
        for (int i = 0; i < m; i++) {
            if (set_a.count(b[i] + target)) {
                return 1;
            }
        }
        
        return -1;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends