//Mahir Ratanpara (DA-IICT)
#include<bits/stdc++.h>
using namespace std;
#define Ff(i,a,n) for(i=a;i<n;i++)
#define Fr(i,a,n) for(i=a;i>n;i--)
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
typedef pair<ll, ll>	pa;
typedef vector<ll>		vc;
typedef vector<pa>		vp;
typedef vector<vc>		vvc;
using matrix=vector<vector<ll> >;

int mpow(int base, int exp);
void outc(vc a);
void oute(vc a);
void out2(matrix a);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

#define white 0
#define gray 1
#define black 2

bool solve1(int root,vector<int> &color,vector<int> adj[])
{
    color[root]=gray;

    for(auto x:adj[root])
    {
        if(color[x]==gray)
        {
            return true;
        }

        if(color[x]==white and solve1(x,color,adj))
        {
            return true;
        }
    }

    color[root]=black;
    return false;
}

//Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<int> color(V, white);
    for(int i=0;i<V;i++)
    {
        if(color[i]==white)
        {
            if(solve1(i,color,adj))
                return true;
        }
    }
    return false;
}

void solve()
{
    int i, j, l, k, p, q, r, x, y, u, v, n, m;
    cin>>n;
    vector<int> g[1003];
    int V=0;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        V=max({V,x,y});
        g[x].push_back(y);
    }
    V++;
    cout<<!(isCyclic(V,g))<<endl;
}

int main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    ll t;
//    t=1;
     cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void outc(vc a)
{
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
}

void oute(vc a)
{
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"\n";
}

void out2(matrix a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();i++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}