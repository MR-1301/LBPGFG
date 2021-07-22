// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

int dp[1001][1001];
class Solution {
public:
    bool solve(string a,string b,string c,int n,int m,int l)
    {
        if(l==0)
            return true;

        if(dp[n][m]!=-1)
            return dp[n][m];

        bool x=false,y= false;
        if(n-1>=0 and a[n-1]==c[l-1])
            x = solve(a,b,c,n-1,m,l-1);

        if(m-1>=0 and b[m-1]==c[l-1])
            y= solve(a,b,c,n,m-1,l-1);

        dp[n][m]= x or y;
        return dp[n][m];
    }
    /*You are required to complete this method */
    bool isInterleave(string a, string b, string c) {
        int n = a.size();
        int m = b.size();
        int l = c.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=-1;
        return solve(a, b, c, n, m, l);
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
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
}  // } Driver Code Ends