// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {

        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
string lcs(int x, int y, string s1, string s2) {
    int dp[x + 1][y + 1];
    for (int i = 0; i < x + 1; i++) {
        for (int j = 0; j < y + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    string s = "";
    int i = x;
    int j = y;
    while (i >= 1 and j >= 1) {

        if (dp[i][j] == dp[i - 1][j - 1]+1) {
            s += s1[i - 1];
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(s.begin(), s.end());
    return s;
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
    // your code here
    string D=lcs(A.size(), B.size(), A, B);;
    string E= lcs(B.size(),C.size(),B,C);
    string F=lcs(A.size(),C.size(),A,C);

    int x=lcs(A.size(),E.size(),A,E).size();
    int y=lcs(B.size(),F.size(),B,F).size();
    int z=lcs(C.size(),D.size(),C,D).size();

    return max({x,y,z});
}