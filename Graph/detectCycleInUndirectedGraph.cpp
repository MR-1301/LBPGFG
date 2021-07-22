// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



#define white 0
#define gray 1
#define black 2
class Solution {
public:
    bool solve(int root,int par,vector<int> &color,vector<int> adj[])
    {
        color[root]=gray;

        for(auto x:adj[root])
        {
            if(color[x]==gray and x!=par)
            {
                return true;
            }

            if(color[x]==white and solve(x,root,color,adj))
            {
                return true;
            }
        }

        color[root]=black;
        return false;
    }

    //Function to detect cycle in a directed graph.
    bool isCycle(int V, vector<int> adj[]) {
        // code here
        vector<int> color(V, white);
        for(int i=0;i<V;i++)
        {
            if(color[i]==white)
            {
                int par=-1;
                if(solve(i,par,color,adj))
                    return true;
            }
        }

        return false;
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
        bool ans = obj.isCycle(V, adj);
        if(ans)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends