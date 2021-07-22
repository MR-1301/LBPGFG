// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    void dfs(int root, vector<int> &vis, vector<int> adj[], stack<int> &s) {
        vis[root] = 1;

        for (int child:adj[root]) {
            if (!vis[child]) {
                dfs(child, vis, adj, s);
            }
        }
        s.push(root);
    }

    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]) {
        stack<int> s;
        vector<int> vis(V, false);
        dfs(0, vis, adj, s);

        //reversing the edges;
        vector<int> trans[V];
        for (int i = 0; i < V; i++) {
            for (auto j:adj[i]) {
                trans[j].push_back(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < V; i++)
            vis[i] = false;

        stack<int> S;
        while (!s.empty()) {
            int root = s.top();
            s.pop();
            if (!vis[root]) {
                ans++;
                dfs(root, vis, trans, s);
            }
        }

        return ans;
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

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends