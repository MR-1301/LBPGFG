// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
vector<vector<int>> solveWordWrap(vector<int>arr, int k) 
{ 
    // Code here
    int i, j;
        int n = arr.size();
        int currlen;

        int cost;

        int dp[n];


        int ans[n];


        dp[n - 1] = 0;
        ans[n - 1] = n - 1;

        for (i = n - 2; i >= 0; i--) {
            currlen = -1;
            dp[i] = INT_MAX;


            for (j = i; j < n; j++) {
                currlen += (arr[j] + 1);

                if (currlen > k)
                    break;

                if (j == n - 1)
                    cost = 0;
                else
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];

                if (cost < dp[i]) {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }

        i = 0;
        vector<vector<int> > res;
        while (i < n) {
            vector<int> temp;
            temp.push_back(i + 1);
            temp.push_back(ans[i] + 1);
            i = ans[i] + 1;
            res.push_back(temp);
        }
        return res;
}   
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		cin >> k;
		Solution obj;
		vector<vector<int>> ans = obj.solveWordWrap(nums, k);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends