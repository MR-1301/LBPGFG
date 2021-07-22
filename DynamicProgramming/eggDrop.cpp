// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        int dp[n+1][k+1];

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<k+1;j++)
            {
                dp[i][j]=0;
            }
        }

        for(int e=1;e<=n;e++)
        {
            for(int f=1;f<=k;f++)
            {
                if(e==1)
                {
                    dp[e][f]=f;
                }
                else if(f==1)
                {
                    dp[e][f]=1;
                }
                else{
                    int mini=INT_MAX;
                    for(int clf=f-1,plf=0;clf>=0;clf--,plf++)
                    {
                        mini=min(mini,max(dp[e][clf],dp[e-1][plf]));
                    }
                    dp[e][f]=mini+1;
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends