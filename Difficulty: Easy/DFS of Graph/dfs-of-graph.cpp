//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Helper function for DFS traversal
    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        visited[node] = true;  // Mark the current node as visited
        result.push_back(node);  // Add it to the result
        
        // Recursively visit all the adjacent nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;  // This will store the DFS traversal
        vector<bool> visited(V, false);  // Visited array to keep track of visited vertices
        
        // Start DFS from the 0th vertex
        dfs(0, adj, visited, result);
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends