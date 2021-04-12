//Mahir Ratanpara (DA-IICT)
#include<bits/stdc++.h>
using namespace std;
#define Ff(i,a,n) for(i=a;i<n;i++)
#define Fr(i,a,n) for(i=a;i>n;i--)
#define ll long long
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef pair<ll, ll>	pa;
typedef vector<ll>		vc;
typedef vector<pa>		vp;
typedef vector<vc>		vvc;
int mpow(int base, int exp); 
void ipgraph(ll n,ll m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];

ll appearsbTimes(vc arr,ll n,ll a,ll b){
    ll sum=0;

    unordered_set<ll> s;
    
    for(auto i:arr)
    {
        sum+=i;
        s.insert(i);
    }

    ll a_sum=0;
    tr(itr,s)
    {
        a_sum+=(*itr);
    }

    sum=a_sum*a-sum;
    ll diff=a-b;
    return sum/diff;
}

int main() {
    FAST;
    ll t, i, j, l,k, p, q, r, x, y, u, v, n, m;
    ll a,b;
    cin>>n>>a>>b;
    vc arr(n);
    Ff(i,0,n)
    {
        cin>>arr[i];
    }

    ll ans=appearsbTimes(arr,n,a,b);
    cout<<ans;
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

void ipgraph(ll n, ll m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}