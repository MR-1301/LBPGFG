// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        vector<int> a(C);
        int ans = INT_MIN;
        vector<vector<int >> pref=M;
        for(int j=0;j<C;j++)
        {
            for(int i=1;i<R;i++)
            {
                pref[i][j]+=pref[i-1][j];
            }
        }

        for (int x = 0; x < R; x++)
        {
            for (int y = x; y < R; y++)
            {
                for (int j = 0; j < C; j++)
                {
                    a[j]=pref[y][j];
                    if(x-1>=0)
                        a[j]-=pref[x-1][j];
                }

                int curr = 0;
                int maxi = INT_MIN;

                for (int i = 0; i < C; i++) {
                    curr += a[i];
                    maxi = max(maxi, curr);
                    if (curr < 0)
                        curr = 0;
                }

                ans = max(ans, maxi);
            }
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends