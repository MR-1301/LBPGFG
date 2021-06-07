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

class Node {
public:
    ll data;
    Node *left;
    Node *right;
};

Node *newNode(ll value) {
    Node *temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//doing levelorder traversal until we find either of left or right child to be empty!!
void insertion(Node *root, ll value) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (!temp->left) {
            temp->left = newNode(value);
            break;
        }
        if (!temp->right) {
            temp->right = newNode(value);
            break;
        }

        q.push(temp->left);
        q.push(temp->right);
    }
}

Node *search(Node *root, ll value) {
    if (root == NULL or root->data == value)
        return root;

    Node *left = search(root->left, value);
    Node *right = search(root->right, value);

    return left?left:right;
}

void deletion(Node *root, ll value) {
    queue<pair<Node *, Node *> > q;
    q.push({root, NULL});
    Node *prev;
    Node *toBeDeleted;
    while (!q.empty()) {
        pair<Node *, Node *> temp = q.front();
        prev = temp.second;
        q.pop();
        if (temp.first->data == value) {
            toBeDeleted = temp.first;
        }

        if (temp.first->left)
            q.push({temp.first->left, temp.first});

        if (temp.first->right)
            q.push({temp.first->right, temp.first});
    }

    swap(toBeDeleted->data, prev->right ? prev->right->data : prev->left->data);

    if (prev->right) {
        free(prev->right);
        prev->right = NULL;
    } else {
        free(prev->left);
        prev->left = NULL;
    }
}

void inOrder(Node *root) {
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrderIt(Node *root) {
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }

}

void preOrder(Node *root) {
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderIt(Node *root) {
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();


        curr = curr->right;
    }

}

void postOrder(Node *root) {
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void postOrderIt(Node *root) {
    return;
}

void levelOrderTraversal(Node *root) {
    cout << "Level Order Traversal:\n";
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

void reverseLevelOrderTraversal(Node *root) {
    cout << "Reverse Level Order Traversal is:\n";
    vc res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        res.pb((q.front())->data);
        if (q.front()->right)
            q.push(q.front()->right);
        if (q.front()->left)
            q.push(q.front()->left);
        q.pop();
    }

    reverse(all(res));
    outc(res);
    cout << endl;
}

ll treeHeight(Node* root,ll* dia)
{
    if(root==NULL)
        return 0;

    ll left = treeHeight(root->left,dia);
    ll right = treeHeight(root->right,dia);
    *dia=max(*dia,left+right+1);
    return max(left,right)+1;
}


void mirror(Node* root)
{
    if(root==NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    swap(root->left,root->right);
}

pair<ll,bool> isBalanced(Node* root)
{
    if(root==NULL)
        return {1LL,true};

    pair<ll,bool> left= isBalanced(root->left);
    pair<ll,bool> right= isBalanced(root->right);

    bool flag=left.second && right.second;
    if(abs(left.first-right.first)>1)
        flag= false;

    return {max(left.first,right.first)+1,flag};
}

ll maxi(Node* root)
{
    if(root==NULL)
        return INT_MIN;

    return max({root->data,maxi(root->left),maxi(root->right)});
}

ll mini(Node* root)
{
    if(root==NULL)
        return INT_MAX;

    return min({root->data,mini(root->left),mini(root->right)});
}

void solve() {
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;
    Node *root = newNode(0);
    insertion(root, 1);
    insertion(root, 2);
    insertion(root, 3);
    insertion(root, 4);
    insertion(root, 5);

//    deletion(root,1);
    levelOrderTraversal(root);
    cout << "Inorder Traversal:\n";
    inOrder(root);
    cout << endl;
    inOrderIt(root);
    cout << endl;
    cout << "Preorder Traversal:\n";
    preOrder(root);
    cout << endl;
    preOrderIt(root);
    cout << endl;

    cout << "Postorder Traversal:\n";
    postOrder(root);
    cout << endl;
//    postOrderIt(root);
//    cout<<endl;

    reverseLevelOrderTraversal(root);

    cout<<"Searching...   ";
    Node* found= search(root,0);
    if(found)
        cout<<found->data<<endl;
    else
        cout<<"Not Found"<<endl;

    ll dia=0;
    cout<<"Height of tree is: "<<treeHeight(root,&dia)<<endl;

    cout<<"diameter of tree is: "<<dia<<endl;
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