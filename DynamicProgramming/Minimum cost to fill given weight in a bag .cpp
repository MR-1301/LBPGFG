// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
public:
    int minimumCost(int cost[], int N, int W)
    {
        int dp[N+1][W+1];
        vector<int> cst(N+1,0);
        for(int i=0;i<N;i++)
        {
            cst[i+1]=cost[i];
        }

        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0)
                {
                    dp[i][j]=1e6+1;
                    continue;
                }
                else if(j==0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j]=dp[i-1][j];
                if(cst[i]!=-1 and j>=i)
                    dp[i][j]=min(dp[i][j],dp[i][j-i]+cst[i]);
            }
        }

//        for(int i=0;i<=N;i++)
//        {
//            for(int j=0;j<=W;j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        if(dp[N][W]==1e6+1)
            return -1;
        return dp[N][W];
    }
};


// { Driver Code Starts.
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";

    }
    return 0;
}  // } Driver Code Ends