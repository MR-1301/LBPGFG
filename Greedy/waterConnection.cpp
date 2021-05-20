// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<bool> vis;
    map<int,pair<int,int> > mp;
public:
    void dfs(int root,int &mini,int &lastVis,vector<pair<int,int> > g[])
    {
        vis[root]= true;
        for(auto x:g[root])
        {
            mini=min(mini,x.second);
            lastVis=x.first;
            if(mp.find(x.first)!=mp.end())
            {
                mini=min(mini,mp[x.first].second);
                lastVis=mp[x.first].first;
                mp.erase(x.first);
            }
            dfs(x.first,mini,lastVis,g);
        }
    }


    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        mp.clear();
        vis.resize(n, false);
        vector<pair<int,int> > g[n+1];
        for(int i=0;i<p;i++)
        {
            g[a[i]].push_back({b[i],d[i]});
        }

        vector<vector<int> > ans;
        for(int i=1;i<=n;i++)
        {
            int mini=INT_MAX;
            int lastVis=i;
            if(!vis[i])
            dfs(i,mini,lastVis,g);
            if(lastVis!=i)
            mp[i]= make_pair(lastVis,mini);
        }

        for(auto it=mp.begin();it!=mp.end();it++)
            ans.push_back({it->first,it->second.first,it->second.second});
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }

    }
    return 0;
}  // } Driver Code Ends