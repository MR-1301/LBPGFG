class Solution {
public:
    void solve(vector<vector<int>>& image,int sr,int sc,int n,int m,int newColor,vector<vector<bool>> &vis)
    {
        cout<<sr<<" "<<sc<<endl;
        if(sr-1>=0 and image[sr-1][sc]==image[sr][sc] and !vis[sr-1][sc])
        {
            vis[sr-1][sc]=true;
            solve(image,sr-1,sc,n,m,newColor,vis);
        }

        if(sr+1<n and image[sr+1][sc]==image[sr][sc] and !vis[sr+1][sc])
        {
            vis[sr+1][sc]=true;
            solve(image,sr+1,sc,n,m,newColor,vis);
        }

        if(sc-1>=0 and image[sr][sc-1]==image[sr][sc] and !vis[sr][sc-1])
        {
            vis[sr][sc-1]=true;
            solve(image,sr,sc-1,n,m,newColor,vis);
        }

        if(sc+1<m and image[sr][sc+1]==image[sr][sc] and !vis[sr][sc+1])
        {
            vis[sr][sc+1]=true;
            solve(image,sr,sc+1,n,m,newColor,vis);
        }

        image[sr][sc]=newColor;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool> > vis(n,vector<bool>(m,false));
        vis[sr][sc]=true;
        solve(image,sr,sc,n,m,newColor,vis);
        return image;
    }
};