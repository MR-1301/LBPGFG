// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int matrixMultiplication(int N, int arr[]) {
        // code here
        pair<int,int> a[N-1];
        for(int i=0;i<N-1;i++)
        {
            a[i].first=arr[i];
            a[i].second=arr[i+1];
        }
        N--;
        int dp[N][N];
        int j = 0;
        int i;
        while (j < N) {
            i = 0;
            int temp = j;
            while (j < N) {
                if (i == j)
                {
                    dp[i][j] = 0;
                    i++;
                    j++;
                    continue;
                }
                int mini = INT_MAX;
                for (int k = i; k < j; k++) {
                    int x = a[i].first * a[k].second * a[j].second;
                    mini = min(mini, dp[i][k] + dp[k+1][j] + x);
                }

                dp[i][j] = mini;
                i++;
                j++;
            }
            j = temp + 1;
        }
        return dp[0][N-1];
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}  // } Driver Code Ends