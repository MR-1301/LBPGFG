// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        vector<int> ans(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        ans[S]=0;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();

            if (ans[curr.second] != curr.first)
                continue;

            for (auto x:adj[curr.second]) {
                if (x[1] + curr.first < ans[x[0]]) {
                    ans[x[0]] = x[1] + curr.first;
                    pq.push({ans[x[0]], x[0]});
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
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends