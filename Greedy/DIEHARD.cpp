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

void solve() {
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;
    cin >> n >> m;
    ll ans=0;
    i=0;
    while(1)
    {
        i++;
        if(n>2 and m>8)   //A+W
        {
            n-=2;
            m-=8;
            ans+=2;
        }
        else if(n>17){      //A+F
            n-=17;
            m+=7;
            ans+=2;
        }
        else{
            ans++;
            break;
        }
    }
    cout<<ans<<endl;
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

//Define solution: For each even-number step, go to water when health > 5 AND armor > 10; otherwise go to fire. (Of course, for odd-number step, go to air.) Obviously, optimal solutions also go to air at odd-number steps (since otherwise it’s not optimal), we can focus only on even-number steps.
//Define measure (this is the hard part). We claim that at each step, the health we have is greater or equal to the health of an optimal solution.
//Proof of above claim: The central idea is that water costs less health than fire; we proceed by induction. At the 2nd step, we go to water if possible; this ensures we have at least the health of any solution. Suppose we have at least the health of an optimal solution at (2k)th step. At (2k+2)th step, if we are still able to go to water, then we keep staying ahead. Else, if we can’t go to water because of insufficient health, any optimal solution can’t either because any optimal solution has health less or equal to our solution (and we must die). If we can’t go to water because of insufficent armor, in any case an optimal solution can go to water at this step, the optimal solution must have been to fire at least once more than our solution to get more armor than ours. So even if we go to fire at this step, the number of times we go to fire is still less or equal to any other solution. Hence, we still have greater or equal health.
//Now we prove the optimality of our solution. We prove by contradiction. Suppose our solution is not optimal. Then there exists an optimal solution that has at least one more even-number step. Before we die (at our last step), we must face one of the two situations: 1. health ≤ 5 OR 2. 5 < health ≤ 20 and armor ≤ 10. In the first situation, similar to the argument above, the optimal solution has health less or equal to ours at the same step and cannot proceed either, a contradiction. In the second situation, it’s possible that the optimal solution has less health but more armor. But, the difference is at least one operation difference (i.e. the optimal solution goes to fire once more than us), which forces the optimal solution to have at least 15 health point less than us. So the optimal solution will have health ≤ 20 - 15 = 5, and cannot proceed further to the next step, a contradiction. Hence our solution must be optimal.
