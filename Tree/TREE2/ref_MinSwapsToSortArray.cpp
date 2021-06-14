// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums) {
        // Code here
        int cnt = 0;
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end());
        unordered_map<int, int> mpa;
        for (int i = 0; i < n; i++) {
            mpa[a[i]] = i;
        }

        vector<bool> vis(n, false);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int x = i;
                vis[x]= true;
                while (nums[x] != a[i]) {
                    curr++;
                    x = mpa[nums[x]];
                    vis[x] = true;
                }
            }
        }
        return curr;
    }
};

// { Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends