//Mahir Ratanpara (DA-IICT)
#include <bits/stdc++.h>
using namespace std;
#define Ff(i, a, n) for (i = a; i < n; i++)
#define Fr(i, a, n) for (i = a; i > n; i--)
#define ll long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
typedef pair<ll, ll> pa;
typedef vector<ll> vc;
typedef vector<pa> vp;
typedef vector<vc> vvc;
using matrix = vector<vector<ll>>;
#define inp(a) Ff(i, 0, a.size()) cin >> a[i];
int mpow(int base, int exp);
void ipgraph(ll n, ll m);
void dfs(int u, int par);
void outc(vc a);
void oute(vc a);
void out2(matrix a);
void sieve();
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];
vc prime;

void solve()
{
	ll i, j, l, k, p, q, r, x, y, u, v, n, m;
    string s;
    cin>>s;
    n=s.size();
    
    stack<char> st;
    for(i=0;i<n;i++)
    {
        if(s[i]=='{')
        st.push(s[i]);
        else{
            if(!st.empty() and st.top()=='{')
            st.pop();
            else
            st.push(s[i]);
        }
    }
    // cout<<"mahir\n";
    // return;
    string ans="";
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    reverse(all(ans));
    int lol=0;
    n=ans.size();
    if(n%2==1)
    {
        cout<<"-1\n";
        return ;
    }
    // cout<<"fhsbfjbsaf\n";
    // return;
    for(i=0;i<n;i++)
    {
        if(ans[i]=='}' and st.empty())
        {
            st.push('{');
            lol++;
        }
        else if(ans[i]=='}'){
            st.pop();
        }
        else{
            st.push(ans[i]);
        }    
    }
    lol+=(st.size())/2;
    cout<<lol<<"\n";
}

int main()
{
	FAST;
	ll t;
	t = 1;
	cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)
			result = ((ll)result * base) % mod;
		base = ((ll)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

void ipgraph(ll n, ll m)
{
	int i, u, v;
	while (m--)
	{
		cin >> u >> v;
		g[u - 1].pb(v - 1);
		g[v - 1].pb(u - 1);
	}
}

void dfs(int u, int par)
{
	for (int v : g[u])
	{
		if (v == par)
			continue;
		dfs(v, u);
	}
}

void outc(vc a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}

void oute(vc a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << "\n";
}

void out2(matrix a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); i++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}

void sieve()
{
	ll MAXN = 2e5 + 1;
	prime.resize(MAXN);
	prime[1] = 1;
	for (ll i = 2; i < MAXN; i++)
		prime[i] = i;

	for (ll i = 4; i < MAXN; i += 2)
		prime[i] = 2;

	for (ll i = 3; i * i < MAXN; i++)
	{
		if (prime[i] == i)
		{
			for (ll j = i * i; j < MAXN; j += i)
				if (prime[j] == j)
					prime[j] = i;
		}
	}
}