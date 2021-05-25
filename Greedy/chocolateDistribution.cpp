// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long leftCandies(long long n, long long m);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        auto ans = leftCandies(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


long long leftCandies(long long n, long long m)
{
    long long sum=(n*(n+1))/2;
    m%=sum;
    long long l=0;
    long long r=n;

    while(abs(r-l)>1)
    {
        long long mid=(r+l)/2;
        sum=(mid*(mid+1))/2;
        if(sum<=m)
        {
            l=mid;
        }
        else{
            r=mid;
        }
    }
    m-=(l*(l+1))/2;
    return m;
}