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

typedef pair<int, int> pa;

void solve() {
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;
    cin >> n >> m;
    vector<pa> trans[n];
    for (i = 0; i < m; i++) {
        cin >> x >> y >> u;
        trans[x].push_back({y, u});
    }

    vc cost(n, 0);
    for (i = 0; i < n; i++) {
        for (auto itr:trans[i]) {
            cost[i] -= itr.second;
            cost[itr.first] += itr.second;
        }
    }

    priority_queue<pa> d, c;
    for (i = 0; i < n; i++) {
        if (cost[i] < 0) {
            d.push({abs(cost[i]), i});
        } else if (cost[i] > 0) {
            c.push({cost[i], i});
        }
    }

    while (d.size() != 0 and c.size() != 0) {
        pa Pd = d.top();
        d.pop();
        pa Pc = c.top();
        c.pop();

        x = min(Pd.ff, Pc.ff);
        Pd.ff -= x;
        Pc.ff -= x;
        cout << "Person " << Pd.ss << " Gives money to " << Pc.ss << " of amount " << x << endl;
        if (Pd.ff > 0)
            d.push(Pd);
        if (Pc.ff > 0)
            c.push(Pc);
    }
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