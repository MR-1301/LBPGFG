// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int N,vector<int> &ans,bool flag)
    {
        if(N==ans.back())
        {
            return;
        }

        if(ans.back()>0 and flag){
            ans.push_back(ans.back()-5);
        }
        else
        {
            ans.push_back(ans.back()+5);
            flag= false;
        }

        solve(N,ans,flag);
    }
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        ans.push_back(N);
        ans.push_back(N-5);
        solve(N,ans, true);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;

        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends