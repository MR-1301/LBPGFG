// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<pair<int, int> > a;
        for (int i = 0; i < n; i++)
            a.push_back({end[i], start[i]});

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            swap(a[i].first, a[i].second);
        }


        int last = a[0].second;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i].first > last) {
                cnt++;
                last = a[i].second;
            }
        }

        return cnt;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends