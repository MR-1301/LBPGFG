// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function

int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=max((i-x>=0)?dp[i-x]:INT_MIN,max((i-y>=0)?dp[i-y]:INT_MIN,(i-z>=0)?dp[i-z]:INT_MIN))+1;
    }
    
    
    return max(0,dp[n]);
}