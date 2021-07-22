// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
    int minJumps(int arr[], int n) {
        // Your code here
        if(n==0)
            return 0;

        int maxLadder=arr[0];
        int currStairs=arr[0];
        int ans=1;

        for(int level=1;level<n;level++)
        {
            if(currStairs==0)
                return -1;
            if(level==n-1)
                return ans;
            maxLadder=max(maxLadder,level+arr[level]);
            currStairs--;
            if(currStairs==0)
            {
                ans++;
                currStairs=maxLadder-level;
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
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends