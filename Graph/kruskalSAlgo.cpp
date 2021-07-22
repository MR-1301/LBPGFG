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

int root(int *a, int A) {
    while (a[A] != A) {
        a[A] = a[a[A]];
        A = a[A];
    }
    return A;
}

void WeightedUnion(int *a, int *s, int x, int y) {
    int root_x = root(a, x);
    int root_y = root(a, y);
    if (s[root_x] < s[root_y]) {
        a[root_x] = a[root_y];
        s[root_y] += s[root_x];
    } else {
        a[root_y] = a[root_x];
        s[root_x] += s[root_y];
    }
}

bool Find(int *a, int x, int y) {
    if (root(a, x) == root(a, y))
        return true;

    return false;
}

vector<pair<pair<int, int>, int> > kruskal_s(vector<vector<pair<int, int>>> adj, int V) {
    vector<pair<pair<int, int>, int> > ans;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j].first > i) {
                edges.push_back({adj[i][j].second, {i, adj[i][j].first}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    int a[V], s[V];
    for (int i = 0; i < V; i++) {
        a[i] = i;
        s[i] = 1;
    }

    for (auto edge:edges) {
        if (ans.size() == V - 1)
            break;
        int x = edge.second.first;
        int y = edge.second.second;
        if (root(a, x) == root(a, y))
            continue;

        WeightedUnion(a, s, x, y);
        ans.push_back({{x, y}, edge.first});
    }

    return ans;
}

void solve() {
    int i, j, l, k, p, q, r, x, y, z, u, v, n, m;
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int> > > adj(V);

    for (i = 0; i < E; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    vector<pair<pair<int, int>, int> > ans = kruskal_s(adj, V);
    for (auto itr:ans)
        cout << itr.first.first << "------" << itr.first.second << "-----" << itr.second << endl;
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
    cin >> t;
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