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


vector<int> prim_s(vector<vector<pair<int, int>>> adj, int V) {
    vector<bool> vis(V, false);
    vector<int> weight(V, INT_MAX);
    vector<int> parent(V, -1);
    weight[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        if (vis[pq.top().second]) {
            pq.pop();
            continue;
        }

        int root = pq.top().second;
        pq.pop();

        vis[root] = true;

        for (auto x:adj[root]) {
            int child = x.first;
            int edge = x.second;
            if (!vis[child]) {
                if (edge < weight[child]) {
                    weight[child] = edge;
                    parent[child] = root;
                    pq.push({weight[child], child});
                }
            }
        }
    }
    return parent;
}

void solve() {
    int i, j, l, k, p, q, r, x, y, z, u, v, n, m;
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int> > >  adj(V);

    for (i = 0; i < E; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    vector<int> prim= prim_s(adj,V);
    for(auto val:prim)
        cout<<val<<" ";
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
     cin>>t;
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