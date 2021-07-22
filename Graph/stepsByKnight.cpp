// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution {
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N) {
        pair<int, int> last = {KnightPos[0], KnightPos[1]};
        pair<int, int> target = {TargetPos[0], TargetPos[1]};

        deque<pair<pair<int, int>, int >> q;
        q.push_back({last, 0});
        int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int ans = -1;
        vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));
        while (!q.empty()) {
            pair<pair<int, int>, int> front = q.front();
            q.pop_front();
            if (front.first == target) {
                ans = front.second;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int x = front.first.first + dx[i];
                int y = front.first.second + dy[i];
                if (x >= 1 and x <= N and y >= 1 and y <= N and !vis[x][y]) {
                    q.push_back({{x, y}, front.second + 1});
                    vis[x][y] = true;

                }
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
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends