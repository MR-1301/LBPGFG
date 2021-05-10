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
#define inp(a) Ff(i,0,a.size()) cin>>a[i];
typedef pair<ll, ll>	pa;
typedef vector<ll>		vc;
typedef vector<pa>		vp;
typedef vector<vc>		vvc;
using matrix=vector<vector<ll> >; 

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

void LPS(int* lps,string t)
{
	int j=0;
	lps[j]=0;
	int i=1;
	int m=t.size();
	while(i<m)
	{
		if(t[i]==t[j])
		{
			j++;
			lps[i++]=j;
		}
		else{
			if(j==0)
			{
				lps[i++]=j;
			}
			else{
				j=lps[j-1];
			}
		}
	}
}

bool KMP(string s,string t)
{
	int n=s.size();
	int m=t.size();
	int i=0;
	int j=0;
	int lps[m];
	LPS(lps,t);

	while(i<n){
		if(s[i]==t[j])
		{
			i++;
			j++;
		}

		if(j==m)
		{
			j=lps[j-1];
			return true;
		}
		else if(i<n and t[j]!=s[i]){
			if(j==0)
			{
				i++;
			}
			else{
				j=lps[j-1];
			}
		}
	}

	return false;
}

void solve()
{
	ll i, j, l, k, p, q, r, x, y, u, v, n, m;
	string s;
	string t;
	cin>>s>>t;

	s+=s;
	// cout<<s<<" ";
	if(KMP(s,t))
	cout<<"true";
	else
	cout<<"false";
}

int main() {
	FAST;
	ll t;
	t=1;
	// cin>>t;
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
		for(int j=0;j<a[i].size();i++)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}