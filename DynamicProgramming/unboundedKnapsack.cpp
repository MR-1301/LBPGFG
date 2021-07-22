// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        long long dp[N+1][W+1];


        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    if(j>=wt[i-1])
                        dp[i][j]=max(dp[i][j],dp[i][j-wt[i-1]]+val[i-1]);

                }

            }

        }

        return (int)dp[N][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];

        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends