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

class maps{
    public:
    vc arr;
    map<ll,ll> mp;

    void insert(ll temp)
    {
        if(mp.find(temp)!=mp.end())
        return;

        mp[temp]=arr.size();
        arr.pb(temp);
    }

    void Delete(ll temp)
    {
        if(mp.find(temp)==mp.end())
        return;

        ll curr=mp[temp];

        mp[arr.back()]=curr;
        swap(arr.back(),arr[curr]);
        arr.pop_back();
        mp.erase(temp);
    }   

    ll find(ll temp)
    {
        if(mp.find(temp)==mp.end())
        return -1;
        return mp[temp];
    }

    ll getRandom()
    {
        srand(time(NULL));
        int random_index = rand() % arr.size();
        return arr[random_index];        
    }
};

int main() {
    FAST;
    ll t, i , j, l,k, p, q, r, x, y, u, v, n, m;
    maps ds; 
    ds.insert(10); 
    ds.insert(20); 
    ds.insert(30); 
    ds.insert(40); 
    cout << ds.find(30) << endl; 
    ds.Delete(20); 
    ds.insert(50); 
    cout << ds.find(50) << endl; 
    cout << ds.getRandom() << endl;
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