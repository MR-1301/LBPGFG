// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int maxSubstring(string S) {
        // Your code goes here
        int prev0 = -1;
        int prev1 = -1;
        int dp[S.size()];
        bool flag=true;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') {
                flag=false;
                dp[i] = max(1, dp[prev0] + 1 - (i - prev0 - 1));
                prev0 = i;
            } else {
                dp[i] = 1;
                prev1 = i;
            }
        }
        if(flag)
            return -1;

        int maxi = 1;
        for (int i = 0; i < S.size(); i++) {
            maxi = max(maxi, dp[i]);
        }
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

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends