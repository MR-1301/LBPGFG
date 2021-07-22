// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int longestSubsequence(int N, int A[]) {
        int dp[N];
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            int maxi = 0;
            for (int j = i + 1; j < N; j++) {
                if (abs(A[i] - A[j]) == 1)
                    maxi = max(maxi, dp[j]);
            }

            dp[i] = maxi + 1;
            ans = max(ans, dp[i]);
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
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestSubsequence(N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends