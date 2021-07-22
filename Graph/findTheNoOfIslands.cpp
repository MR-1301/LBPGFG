// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution {
public:
    //Function to find the number of islands.
    int dx[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
    int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

    void dfs(int x, int y, vector<vector<char>> grid, vector<vector<bool>> &vis, int n, int m) {
        vis[x][y] = true;

        for (int d = 0; d < 8; d++) {
            int l = x + dx[d];
            int r = y + dy[d];
            if ((l >= 0 and l < n and r>= 0 and r < m) and grid[l][r]=='1' and !vis[l][r])
                dfs(l, r, grid, vis, n, m);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, vis, n, m);
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends