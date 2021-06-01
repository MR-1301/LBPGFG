// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
public:

    void solve(vector<vector<int>> &m,int n,int x,int y, vector<vector<bool> > &vis,vector<string> &ans,string &temp)
    {

        if(x==n-1 and y==n-1)
        {
            ans.push_back(temp);
            return;
        }

        if(x+1<n and !vis[x+1][y] and m[x+1][y]==1)
        {
            temp+="D";
            vis[x+1][y]=true;
            solve(m,n,x+1,y,vis,ans,temp);
            vis[x+1][y]= false;
            temp.pop_back();
        }

        if(x-1>=0 and !vis[x-1][y] and m[x-1][y]==1)
        {
            temp+="U";
            vis[x-1][y]=true;
            solve(m,n,x-1,y,vis,ans,temp);
            vis[x-1][y]=false;
            temp.pop_back();
        }

        if(y+1<n and !vis[x][y+1] and m[x][y+1]==1)
        {
            temp+="R";
            vis[x][y+1]=true;
            solve(m,n,x,y+1,vis,ans,temp);
            vis[x][y+1]= false;
            temp.pop_back();
        }

        if(y-1>=0 and !vis[x][y-1] and m[x][y-1]==1)
        {
            temp+="L";
            vis[x][y-1]=true;
            solve(m,n,x,y-1,vis,ans,temp);
            vis[x][y-1]= false;
            temp.pop_back();
        }
    }


    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool> > vis(n,vector<bool>(n, false));
        vector<string> ans;
        string temp="";
        if(m[0][0]==0)
            return ans;
        vis[0][0]=true;
        solve(m,n,0,0,vis,ans,temp);
        sort(ans.begin(),ans.end());
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends