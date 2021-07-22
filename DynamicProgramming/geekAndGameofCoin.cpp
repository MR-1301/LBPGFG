// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {

public:
    int findWinner(int N, int X, int Y) {
        // Your code goes here
        bool dp[N + 1];
        dp[0] = false;
        dp[1] = true;

        for (int i = 2; i <= N; i++) {
            dp[i] = !((i - 1 < 0 or dp[i - 1]) and (i - X < 0 or dp[i - X]) and (i - Y < 0 or dp[i - Y]));
        }

        return dp[N];
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
        int n, x, y;
        cin >> n >> x >> y;


        Solution ob;
        cout << ob.findWinner(n, x, y);
        cout << "\n";

    }
    return 0;
}  // } Driver Code Ends