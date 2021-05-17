// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
public:
    string secFrequent(string arr[], int n) {
        unordered_map<string, int> mp;
        int maxi = INT_MIN;
        string ans;
        string ans1;
        int maxi1;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if (itr->second > maxi) {
                maxi1 = maxi;
                ans1 = ans;
                maxi = itr->second;
                ans = itr->first;
            } else if (itr->second > maxi1) {
                maxi1 = itr->second;
                ans1 = itr->first;
            }
        }

        return ans1;
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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends