// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


string longestPalin (string S)
{
    // your code here
    int left=0;
    int right=0;
    int n=S.size();
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        //odd length
        int l=i-1;
        int r=i+1;
        while(l>=0 and r<n and S[l]==S[r])
        {
            if(r-l+1>maxi)
            {
                left=l;
                right=r;
                maxi=(r-l+1);
            }
            l--;
            r++;
        }
        
        l=i;
        r=i+1;
        while(l>=0 and r<n and S[l]==S[r])
        {
            if(r-l+1>maxi)
            {
                left=l;
                right=r;
                maxi=(r-l+1);
            }
            l--;
            r++;
        }
    }

    string ans;
    for(int i=left;i<=right;i++)
    ans+=S[i];
    return ans;
}