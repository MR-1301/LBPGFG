// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        //Your code here
        int n=str.size();
        long long dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }

        }


        int temp=0;
        int i=0;
        int j=0;
        long long mod=1e9+7;
        while(temp<n)
        {
            i=0;
            j=temp;

            while(j<n)
            {
                if(i==j)
                {
                    dp[i][j]=1;
                    i++;j++;
                    continue;
                }

                if(str[i]==str[j])
                  dp[i][j]=((dp[i+1][j]+dp[i][j-1])%mod+1)%mod;
                else
                    dp[i][j]=((dp[i+1][j]+dp[i][j-1])%mod-dp[i+1][j-1]+mod)%mod;

                i++;
                j++;
            }
            temp++;
        }

        return dp[0][n-1];
    }

};

// { Driver Code Starts.
// Driver program
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends