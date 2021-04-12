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

int countPairs(int a[], int b[], int n, int m) 
{ 
  
    // To store the required count 
    int cnt = 0; 
  
    // Set to store the sum 
    // obtained for each pair 
    unordered_set<int> s; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
  
            // Sum of the current pair 
            int sum = a[i] + b[j]; 
  
            // If the sum obtained is distinct 
            if (s.count(sum) == 0) { 
  
                // Increment the count 
                cnt++; 
  
                // Insert sum in the set 
                s.insert(sum); 
            } 
        } 
    } 
  
    return cnt; 
} 

int main() {
    FAST;
    ll t, i, j, l,k, p, q, r, x, y, u, v, n, m;
    
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