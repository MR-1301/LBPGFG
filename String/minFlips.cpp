// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
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

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n=S.size();
    int cnt=0;
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        a+=(cnt)^(S[i]-'0');
        b+=(1-cnt)^(S[i]-'0');
        cnt=1-cnt;
    }
    return min(a,b);
}