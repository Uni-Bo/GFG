//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        while(s[0]=='0') 
        {
         s.erase(s.begin());
        }
        //cout<<s<<"\n";
        int i=s.size()-1;
        char c='1';
        while(c=='1' && i>=0){
            if(s[i]=='1')
            {
                s[i]='0';
                i--;
            }
            else
            {
                s[i]='1';
                c='0';
            }
        }
        if (s[0]=='0')
            s='1'+s;
        if(s.empty())
            s='1';
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends