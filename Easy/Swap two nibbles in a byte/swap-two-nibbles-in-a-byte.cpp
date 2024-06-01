//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int higher_nibble = (n & 0xF0) >> 4;
        // Extract and shift the lower nibble to the higher position
        int lower_nibble = (n & 0x0F) << 4;
        // Combine the swapped nibbles
        return (higher_nibble | lower_nibble);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends