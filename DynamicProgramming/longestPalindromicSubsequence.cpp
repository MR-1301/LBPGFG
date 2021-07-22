// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


//User function Template for C++

int longestPalinSubseq (string S)
{
    // your code here
    int n=S.size();
    int dp[n][n];

    int i=0;
    int j=0;
    int temp;
    while(j<n)
    {
        i=0;
        temp=j+1;
        while(j<n)
        {
            if(j-i==0)
                dp[i][j]=1;
            else if(j-i==1)
                dp[i][j]=(S[i]==S[j])?2:1;
            else if(S[i]==S[j])
                dp[i][j]=2+dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

            i++;
            j++;
        }
        j=temp;
    }

    return dp[0][n-1];
}