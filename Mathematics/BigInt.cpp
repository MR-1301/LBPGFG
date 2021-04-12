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

string longDivision(string number, int divisor) 
{ 
    // As result can be very large store it in string 
    string ans; 
  
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
  
    // Repeatedly divide divisor with temp. After 
    // every division, update temp to include one 
    // more digit. 
    while (number.size() > idx) { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
  
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
  
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
  
    // else return ans 
    return ans; 
} 

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}

string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

void solve()
{
  	ll i, j, l, p, q, r, x, y, u, v, m;
    string total,diff;
    cin>>total>>diff;

    string n,k;
    string div="2";
    n=longDivision(findDiff(total,diff),2);
    reverse(all(n));
    while(n.size()>1 and n.back()=='0')
    n.pop_back();
    reverse(all(n));
    k=findDiff(total,n);
    reverse(all(k));
    while(k.size()>1 and k.back()=='0')
    k.pop_back();
    reverse(all(k));
    cout<<k<<"\n";
    cout<<n<<"\n";

}

int main() {
    FAST;
    ll t;
    t=10;
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