// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


#define white 0
#define gray 1
#define black 2

class Solution {
public:
    bool solve(int root,vector<int> &color,vector<int> adj[])
    {
        color[root]=gray;

        for(auto x:adj[root])
        {
            if(color[x]==gray)
            {
                return true;
            }

            if(color[x]==white and solve(x,color,adj))
            {
                return true;
            }
        }

        color[root]=black;
        return false;
    }

    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> color(V, white);
        for(int i=0;i<V;i++)
        {
            if(color[i]==white)
            {
                if(solve(i,color,adj))
                    return true;
            }
        }
    }
};

// { Driver Code Starts.


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends