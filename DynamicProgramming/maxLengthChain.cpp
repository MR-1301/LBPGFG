// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct val {
    int first;
    int second;
};


int maxChainLen(struct val p[], int n);

int main() {
    // your code goes here
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
        val p[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool cmp(struct val &a, struct val &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n) {
    vector<int> dp(n, 1);
    sort(p, p + n, cmp);
    int ans = INT_MIN;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[i].first > p[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}