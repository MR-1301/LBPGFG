// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minimumNumberOfSwaps(string S) {
        // code here
        int curr=0;
        int ans=0;
        for(int i=0;i<S.size();i++)
        {
            if(curr<0 and S[i]=='[')
                ans+=abs(curr);
            if(S[i]=='[')
                curr++;
            if(S[i]==']')
                curr--;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
}   // } Driver Code Ends