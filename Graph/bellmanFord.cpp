// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> weight(n, INT_MAX);
        weight[0] = 0;
        int flag = 0;
        vector<int> tempwt;
        for (int i = 0; i < n; ++i) {
            flag = 0;
            tempwt = weight;
            for (auto x:edges) {
                if (tempwt[x[0]] == INT_MAX)
                    continue;
                else {
                    if (tempwt[x[0]] + x[2] < weight[x[1]]) {
                        flag = 1;
                        weight[x[1]] = tempwt[x[0]] + x[2];
                    }
                }
            }
        }

        return flag;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends