// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {


public:
    long long getCount(int N) {
        // Your code goes here
        vector<vector<int> > neigh(10);
        vector<int> temp;
        for (int i = 0; i < 10; i++)
            neigh.push_back(temp);

        neigh[0].insert(neigh[0].end(), {8});
        neigh[1].insert(neigh[1].end(), {2, 4});
        neigh[2].insert(neigh[2].end(), {1, 3, 5});
        neigh[3].insert(neigh[3].end(), {2, 6});
        neigh[4].insert(neigh[4].end(), {1, 5, 7});
        neigh[5].insert(neigh[5].end(), {2, 4, 6, 8});
        neigh[6].insert(neigh[6].end(), {3, 5, 9});
        neigh[7].insert(neigh[7].end(), {4, 8});
        neigh[8].insert(neigh[8].end(), {0, 5, 7, 9});
        neigh[9].insert(neigh[9].end(), {6, 8});


        vector<long long> dp(10, 1);
        for (int i = 2; i <= N; i++) {
            vector<long long> ndp=dp;
            for (int j = 0; j < 10; j++) {
                for (auto x:neigh[j]) {
                    ndp[x] += dp[j];
                }
            }
            dp = ndp;
        }

        return accumulate(dp.begin(), dp.end(), 0LL);
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


        Solution ob;
        cout << ob.getCount(n) << "\n";

    }
    return 0;
}
// } Driver Code Ends