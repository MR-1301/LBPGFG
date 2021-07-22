// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends

class Solution {
public:
    vector<pair<int, int>> adj[1001];
    unordered_set<int> path;
    int curr = 0;
    bool flag = false;
    int K;

    void solve(int root) {
        if (curr >= K)
            flag = true;

        for (auto x:adj[root]) {
            if (path.find(x.first) != path.end())
                continue;

            path.insert(x.first);
            curr += x.second;
            solve(x.first);
            path.insert(x.first);
            curr -= x.second;
            path.erase(x.first);
        }
    }

    bool pathMoreThanK(int V, int E, int k, int *a) {
        K = k;
        for (int i = 0; i < 3 * E; i += 3) {
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }

        path.insert(0);
        solve(0);
        return flag;
    }
};

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3 * E + 1];
        for (int i = 0; i < 3 * E; i++) {
            cin >> a[i];
        }

        Solution obj;
        if (obj.pathMoreThanK(V, E, K, a)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

    }
    return 0;
}  // } Driver Code Ends