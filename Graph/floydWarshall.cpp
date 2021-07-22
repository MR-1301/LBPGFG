// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n=matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j]=INT_MAX;
            }

        }

        for(int i=0;i<n;i++){
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<n;y++)
                {
                    int ft=matrix[x][i];
                    int st=matrix[i][y];

                    if(ft+st<matrix[x][y] and ft!=INT_MAX and st!=INT_MAX)
                        matrix[x][y]=ft+st;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==INT_MAX)
                    matrix[i][j]=-1;
            }
        }
    }
};

// { Driver Code Starts.
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
     int tc;

    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends