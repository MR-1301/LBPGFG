// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       vector<vector<long long> >dp(m,vector<long long>(n+1,0));
       
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<=n;j++)
           {
               if(j==0)
               dp[i][j]=1;
               else
               {
                   if(i!=0)
                   dp[i][j]+=dp[i-1][j];
                   
                   if(j-S[i]>=0)
                   dp[i][j]+=dp[i][j-S[i]];
               }
           }
       }
       
       return dp[m-1][n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends