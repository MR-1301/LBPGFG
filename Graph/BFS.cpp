// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (auto y:adj[x]) {
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
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
}  // } Driver Code Ends