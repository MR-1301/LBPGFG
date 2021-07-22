// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int root,vector<int> adj[],vector<int> &vis,vector<int> &col,int color)
    {
        vis[root]=1;
        col[root]=color;

        for(auto child:adj[root])
        {
            if(!vis[child])
            {
                if(!dfs(child,adj,vis,col,color xor 1))
                    return false;
            }
            else if(col[root]==col[child])
                return false;
        }

        return true;
    }
    bool isBipartite(int V, vector<int>adj[]){
        // Code here
        vector<int> vis(V,0);
        vector<int> col(V,-1);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,adj,vis,col,0))
                    return false;
            }
        }

        return true;
    }

};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if(ans)cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends