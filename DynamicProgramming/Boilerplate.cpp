//Mahir Ratanpara (DA-IICT)
#include<bits/stdc++.h>

using namespace std;
#define Ff(i, a, n) for(i=a;i<n;i++)
#define Fr(i, a, n) for(i=a;i>n;i--)
#define ll long long
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define inp(a) Ff(i,0,a.size()) cin>>a[i];
typedef pair<ll, ll> pa;
typedef vector<ll> vc;
typedef vector<pa> vp;
typedef vector<vc> vvc;
using matrix = vector<vector<ll> >;

int mpow(int base, int exp);

void ipgraph(ll n, ll m);

void dfs(int u, int par);

void outc(vc a);

void oute(vc a);

void out2(matrix a);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];

class Solution {
public:

    struct cmp {
        constexpr bool operator()(
                pair<int, int> const &A,
                pair<int, int> const &B)
        const noexcept {
            if (A.first == B.first)
                return A.second < B.second;
            return A.first < B.first;
        }
    };

    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i=0;i<servers.size();i++)
        {
            pq.push({servers[i],i});
        }

        map<int, vector<int> > mp;
        queue<int> taskQueue;
        int time = 0;
        while(!taskQueue.empty())
        {
            if(time<tasks.size())
                taskQueue.push(tasks[time]);

            auto itr=mp.begin();
            if(time==itr->first)
            {
                for(auto x:itr->second)
                {
                    pq.push({servers[x],x});
                }
                mp.erase(itr);
                while(!taskQueue.empty() and !pq.empty())
                {
                    pair<int,int> curr=pq.top();
                    pq.pop();
                    mp[time+taskQueue.front()].push_back(curr.second);
                    ans.push_back(curr.second);
                    taskQueue.pop();
                }
            }
            time++;
        }
        return ans;
    }
};

void solve() {
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;

}

int main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    ll t;
    t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll) result * base) % mod;
        base = ((ll) base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(ll n, ll m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
}

void dfs(int u, int par) {
    for (int v:g[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

void outc(vc a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}

void oute(vc a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\n";
}

void out2(matrix a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); i++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}