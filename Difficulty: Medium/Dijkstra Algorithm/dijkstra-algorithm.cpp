//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Initialize the distance vector with a large value (infinity)
        vector<int> dist(V, 1e9);
    
        // Priority queue to store {distance, node}, with smallest distance on top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
        // Set the distance to the source node as 0 and push it to the priority queue
        dist[src] = 0;
        pq.push({0, src});
    
        // Continue until the priority queue is empty
        while (!pq.empty())
        {
            // Get the node with the smallest distance
            int node = pq.top().second;
            int node_dist = pq.top().first;
            pq.pop();
    
            // Iterate through all adjacent nodes
            for (auto& n : adj[node])
            {
                int node_nxt = n[0];
                int dist_nxt = n[1];
    
                // If a shorter path to the adjacent node is found
                if (node_dist + dist_nxt < dist[node_nxt])
                {
                    // Update the distance and push the node into the queue
                    dist[node_nxt] = node_dist + dist_nxt;
                    pq.push({dist[node_nxt], node_nxt});
                }
            }
        }
    
        return dist;
    }

};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends