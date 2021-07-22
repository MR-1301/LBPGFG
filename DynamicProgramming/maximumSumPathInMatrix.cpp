// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maximumPath(int N, vector<vector<int>> Matrix) {
        int dp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = max({(i - 1 >= 0) ? dp[i - 1][j] : 0, (i - 1 >= 0 and j - 1 >= 0) ? dp[i - 1][j - 1] : 0,
                                (i - 1 >= 0 and j+1<N) ? dp[i-1][j + 1] : 0}) + Matrix[i][j];
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<N;i++)
            maxi=max(maxi,dp[N-1][i]);

        return maxi;
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
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}  // } Driver Code Ends