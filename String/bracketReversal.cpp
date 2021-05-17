// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int curr=0;
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
            curr++;
        else
            curr--;

        if(curr<0)
        {
            curr=1;
            ans++;
        }

    }
    if(curr%2==1)
        return -1;
    return ans+(curr)/2;
}