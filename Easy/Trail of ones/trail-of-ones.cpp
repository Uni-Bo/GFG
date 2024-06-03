//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

const int MOD = 1e9 + 7;

// Function to compute 2^n % MOD
long long powerOfTwo(int n) {
    long long result = 1;
    long long base = 2;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        n /= 2;
    }
    return result;
}

// Function to compute the (n+2)-th Fibonacci number % MOD
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

// Function to compute the number of binary strings of length n that contain consecutive 1's
int numberOfConsecutiveOnes(int n) {
    long long totalStrings = powerOfTwo(n);
    long long fib_n_plus_2 = fibonacci(n + 2);
    long long result = (totalStrings - fib_n_plus_2 + MOD) % MOD;
    return result;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends