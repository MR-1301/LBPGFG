// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(M[a][b])
            {
                s.push(b);
            }
            else if(!M[a][b])
            {
                s.push(a);
            }
        }
        
        int ans=s.top();
        
        int x=0,y=0;
        for(int i=0;i<n;i++)
        x+=M[ans][i];
        
        for(int i=0;i<n;i++)
        y+=M[i][ans];
        
        return (x==0 and y==n-1)?ans:-1;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends