// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        // your code her
        vector<int> dp;

        for(int i=0;i<n;i++)
        {
            auto itr= upper_bound(dp.begin(),dp.end(),a[i]);
            if(itr==dp.end())
                dp.push_back(a[i]);
            else
                *itr=a[i];
        }

        return (int)dp.size();
    }
};

// { Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--) {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends