// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    static long long minCost(long long arr[], long long n) {
        long long ans=0;
        priority_queue<long long , vector<long long >,
                greater<long long > > pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }

        while(pq.size()!=1)
        {
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            ans+=x+y;
            pq.push(x+y);
        }

        return ans;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends