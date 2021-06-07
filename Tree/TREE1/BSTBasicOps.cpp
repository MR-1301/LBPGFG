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


//BST is a binary tree where left subtree will always have lesser or equal number than in current node
// and right subtree will always have greater than the current number
class Node {
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *search(Node *root, int data) {
    if (!root or root->data == data)
        return root;

    if (root->data > data)
        return search(root->left, data);

    return search(root->right, data);
}

Node *insertion(Node *root, int data) {
    //Base case
    if (!root)
        return newNode(data);

    if (root->data >= data)
        root->left = insertion(root->left, data);
    else
        root->right = insertion(root->right, data);

    return root;
}

pair<Node *, Node *> SforD(Node *root, Node *prev, int data) {
    if (!root or root->data == data)
        return {root, prev};

    if (root->data < data)
        return SforD(root->left, root, data);

    return SforD(root->right, root, data);
}

void deleteLeaf(Node *curr, Node *parent) {
    if(parent==NULL)
    {
        free(curr);
        return;
    }
    if (parent->left == curr)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(curr);
}

void deleteOneChild(Node *curr, Node *parent) {
    if (parent->left == curr) {
        parent->left = (curr->left ? curr->left : curr->right);
    } else {
        parent->right = (curr->left ? curr->left : curr->right);
    }
    free(curr);
}

void deleteTwoChild(Node *curr) {
    Node *temp = curr->right;
    while (temp->left != NULL)
        temp = temp->left;

    curr->data = temp->data;

    pair<Node *, Node *> lol = SforD(curr->right, curr, curr->data);
    if (lol.first->left or lol.first->right)
        deleteOneChild(lol.first, lol.second);
    else
        deleteLeaf(lol.first, lol.second);
}

void deletion(Node *root,Node* prev,int data) {
    pair<Node *, Node *> curr = SforD(root, prev, data);

    if(curr.first==NULL)
        return;

    if (curr.first->left and curr.first->right)
        deleteTwoChild(curr.first);
    else if (curr.first->left or curr.first->right)
        deleteOneChild(curr.first, curr.second);
    else
        deleteLeaf(curr.first, curr.second);
}

//Function to delete a node from BST.
Node *deleteNode(Node *root,  int X)
{
    if(root->data==X and !root->right and !root->left)
    {
        root=NULL;
        return root;
    }

    if(root->data==X and (!root->right or !root->left))
    {
        if(root->right)
        {
            Node* curr=root->right;
            while(curr->left!=NULL)
                curr=curr->left;

            root->data=curr->data;
            deletion(root->right,root,curr->data);
        }
        else{
            Node* curr=root->left;
            while(curr->right!=NULL)
                curr=curr->right;

            root->data=curr->data;
            deletion(root->left,root,curr->data);
        }

        return root;
    }
    deletion(root,NULL,X);
    return root;
}

bool isBST(Node* root,int min,int max)
{
    if(!root)
        return true;

    if(root->data>max or root->data<min)
        return false;

    return isBST(root->left,min,root->data-1) && isBST(root->right,root->data+1,max);
}

int minValue(Node* root)
{
    while (root->left!=NULL)
        root=root->left;

    return root->data;
}

int max(Node* root)
{
    while(root->right!=NULL)
        root=root->right;
    return root->data;
}



void solve() {
    int i, j, l, k, p, q, r, x, y, u, v, n, m;
    Node *BST = newNode(7);

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
    // cin>>t;
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