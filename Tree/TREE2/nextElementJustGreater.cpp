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
void ipgraph(ll n,ll m);
void dfs(int u, int par);
void outc(vc a);
void oute(vc a);
void out2(matrix a);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    Node *insertion(Node *root, int data) {
    //Base case
        if (!root)
            return new Node(data);


        if (root->key > data)
            root->left = insertion(root->left, data);
        else
            root->right = insertion(root->right, data);

        return root;
    }

    void findPreSuc(Node *root, Node *&suc, int key) {
        if(!root)
            return;
        if (root->key == key) {
            if (root->right) {
                Node *temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;

                suc = temp;
            }
        }

        if (root->key > key)
        {
            suc=root;
            findPreSuc(root->left, suc, key);
        }
        else
        {
            findPreSuc(root->right,suc,key);
        }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        Node* root=NULL;
        vector<int> ans=nums;
        for(int i=(int)nums.size()-1;i>=0;i--)
        {
            root=insertion(root,nums[i]);
        }

        for(int i=(int)nums.size()-1;i>=0;i--)
        {
            Node* suc=NULL;

            findPreSuc(root,suc,nums[i]);
            if(suc)
                ans[i]=suc->key;
            else
                ans[i]=-1;
        }

        return ans;
    }
};

void solve()
{
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;

}

int main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
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