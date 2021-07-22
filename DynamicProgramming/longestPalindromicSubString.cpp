// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int longestPalinSubseq(string A);

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


//User function Template for C++

int longestPalinSubseq(string S) {
    // your code here
    int n = S.size();
    bool dp[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j]= false;
        }
    }
    int i;
    int j = 0;

    while (j < n) {
        i = 0;
        int temp = j;
        while (j < n) {
            if (i == j)
                dp[i][j] = true;
            else if (abs(j - i) == 1) {
                if (S[i] == S[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            } else {
                if (S[i] == S[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = false;
            }
            i++;
            j++;
        }

        j = temp + 1;
    }
    int maxi = 1;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (dp[i][j]) {
                maxi = max(maxi, abs(i - j) + 1);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return maxi;
}