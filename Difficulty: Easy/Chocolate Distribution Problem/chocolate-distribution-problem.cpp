//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    vector<long long>win;
    for(long long i=0;i<m;i++)
    {
        win.insert(win.begin(),a[i]);
    }
    long long mn=abs(win[0]-win[m-1]);
    for(long long i=m;i<n;i++)
    {
        win.pop_back();
        win.insert(win.begin(),a[i]);
        
        if(abs(win[0]-win[m-1])<mn)
        {
            mn=abs(win[0]-win[m-1]);
        }
    }
    return mn;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends