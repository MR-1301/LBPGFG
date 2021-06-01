// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    static bool solve(string s,int l,int r)
    {
        if(l>=r)
            return true;
        if(s[l]!=s[r])
            return false;
        return solve(s,l+1,r-1);
    }
    string is_palindrome(int n)
    {
        string s= to_string(n);
        if(solve(s,0,(int)s.size()-1))
        return "Yes";
        return "No";
    }
};

// { Driver Code Starts.
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        Solution ob;
        string ans = ob.is_palindrome(n);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends