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
using matrix=vector<vector<int> >; 
#define inp(a) Ff(i,0,a.size()) cin>>a[i];
int mpow(int base, int exp); 
void ipgraph(ll n,ll m);
void dfs(int u, int par);
void outc(vc a);
void oute(vc a);
void out2(matrix a);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];


void multiply(int F[2][2], int M[2][2]); 
void power(int F[2][2], int n); 
  
// Function that returns nth Fibonacci number 
int fib(int n) 
{ 
    int F[2][2] = {{1, 1}, {1, 0}}; 
    if (n == 0) 
        return 0; 
    power(F, n - 1); 
  
    return F[0][0]; 
} 
  
// Optimized version of power() in method 4 
void power(int F[2][2], int n) 
{ 
    if(n == 0 || n == 1) 
       return; 
    int M[2][2] = {{1, 1}, {1, 0}}; 
      
    power(F, n / 2); 
    multiply(F, F); 
      
    if (n % 2 != 0) 
        multiply(F, M); 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
    int x = ((F[0][0] * M[0][0])%mod + (F[0][1] * M[1][0])%mod)%mod; 
    int y = ((F[0][0] * M[0][1])%mod + (F[0][1] * M[1][1])%mod)%mod; 
    int z = ((F[1][0] * M[0][0])%mod + (F[1][1] * M[1][0])%mod)%mod; 
    int w = ((F[1][0] * M[0][1])%mod + (F[1][1] * M[1][1])%mod)%mod; 
      
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
} 

void solve()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    
    a=(fib(n+1));
    b=(fib(m+2));

    cout<<(b-a+mod)%mod<<"\n";
}

int main() 
{
    FAST;
    ll t;
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
    for(int j=0;j<a[i].size();j++)
    cout<<a[i][j]<<" ";
    cout<<"\n";
  }
}