// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree


class Solution {
public:
    //Function to find if the given edge is a bridge in graph.
    void bridgeUtil(vector<int> adj[], int u, bool visited[], int disc[],
                    int low[], int parent[]) {
        // A static variable is used for simplicity, we can
        // avoid use of static variable by passing a pointer.
        static int time = 0;

        // Mark the current node as visited
        visited[u] = true;

        // Initialize discovery time and low value
        disc[u] = low[u] = ++time;

        // Go through all vertices aadjacent to this

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;  // v is current adjacent of u

            // If v is not visited yet, then recur for it
            if (!visited[v]) {
                parent[v] = u;
                bridgeUtil(adj, v, visited, disc, low, parent);

                // Check if the subtree rooted with v has a
                // connection to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // If the lowest vertex reachable from subtree
                // under v is  below u in DFS tree, then u-v
                // is a bridge
            }

                // Update low value of u for parent function calls.
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d) {
        bool *visited = new bool[V];
        int *disc = new int[V];
        int *low = new int[V];
        int *parent = new int[V];

        // Initialize parent and visited arrays
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            visited[i] = false;
        }

        // Call the recursive helper function to find Bridges
        // in DFS tree rooted with vertex 'i'
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                bridgeUtil(adj, i, visited, disc, low, parent);

        return low[d] > disc[c];
    }
};

// { Driver Code Starts.


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends