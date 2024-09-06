//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int V, int s, vector<int> adj[], vector<int>& res)
    {
        vector<bool> vis(V, false);  // To keep track of visited nodes
        queue<int> q;
        
        q.push(s);
        vis[s] = true;
        
        while(!q.empty())
        {
            int node = q.front();  // Get the front node
            q.pop();
            res.push_back(node);  // Add it to the result list
            
            // Traverse all adjacent vertices of the current node
            for(int i = 0; i < adj[node].size(); i++)
            {
                if(!vis[adj[node][i]])  // If the adjacent node is not visited
                {
                    q.push(adj[node][i]);  // Push it into the queue
                    vis[adj[node][i]] = true;  // Mark as visited
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        // Call BFS starting from node 0 (assuming connected graph)
        bfs(V, 0, adj, res);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends