// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool solve(int root, vector<int> adj[], int m, int V, vector<int> &color) {
    if (root == V)
        return true;

    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (auto x:adj[root]) {
            if (color[x] == i) {
                flag = false;
                break;
            }
        }

        if (flag) {
            color[root] = i;
            if (solve(root + 1, adj, m, V, color))
                return true;
            color[root] = -1;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    // your code here
    vector<int> adj[V];
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    return solve(0, adj, m, V, color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends