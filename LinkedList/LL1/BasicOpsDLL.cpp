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

class LL {
public:
    int value;
    LL *next;
    LL* prev;
public:
    static LL *createNewNode(int data) {
        LL *newNode = new LL();
        newNode->value = data;
        newNode->next = NULL;
        newNode->prev=NULL;
        return newNode;
    }

    void addNodeAtBegin(int data) {
        LL *newNode = createNewNode(this->value);
        this->value = data;
        this->next->prev=newNode;
        newNode->next = this->next;
        newNode->prev=this;
        this->next = newNode;

    }

    void addNodeAtEnd(int data) {
        LL *newNode = createNewNode(data);
        LL *temp = this;
        bool flag=true;
        while (temp->next != this or flag) {
            temp = temp->next;
            flag= false;
        }

        newNode->prev=temp;
        temp->next = newNode;
    }

    LL *Search(int data) {
        LL *temp = this;
        bool flag=true;
        while (temp != NULL or flag) {
            if (temp->value == data) {
                return temp;
            }
            flag= false;
            temp = temp->next;
        }
        return NULL;
    }

    void Delete(int data) {
        LL *temp = this;

        if (this->value == data) {
            if (this->next == NULL) {
                cout << "this will lead to delete of whole linked List\n";
                return;
            }
            LL *lol = this->next;
            this->value = this->next->value;
            this->next = this->next->next;
            lol->next->prev=this;
            delete lol;
            return;
        }

        while (temp->next != NULL and temp->next->value != data) {
            temp = temp->next;
        }

        if (temp->next == this)
            return;

        LL *lol = temp->next;
        temp->next = temp->next->next;
        lol->next->prev=temp;
        delete lol;
    }


    int length() {
        int cnt = 0;
        LL *temp = this;
        bool flag=true;
        while (temp != NULL or flag) {
            cnt++;
            flag=false;
            temp = temp->next;
        }
        return cnt;
    }

    LL *getNthNode(int nth) {
        if (nth > this->length())
            return NULL;

        int cnt = nth-1;
        LL *temp = this;
        bool flag=true;
        while (cnt-- and (temp != NULL or flag)) {
            temp = temp->next;
            flag=false;
        }

        return temp;
    }

    int count(int data)
    {
        LL* temp=this;
        int cnt=0;
        bool flag=true;
        while (temp!=NULL or flag)
        {
            if(temp->value==data)
                cnt++;
            temp=temp->next;
            flag= false;
        }
        return cnt;
    }

    pair<int,int> minmax()
    {
        LL* temp=this;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        bool flag=true;
        while(temp!=NULL or flag)
        {
            mini=min(mini,temp->value);
            maxi=max(maxi,temp->value);
            temp=temp->next;
            flag= false;
        }

        return {mini,maxi};
    }

    void print() {
        LL *temp = this;
        bool flag= true;
        while (temp != NULL or flag) {
            cout << temp->value << " ";
            temp = temp->next;
            flag=false;
        }
    }
};

void solve() {
    ll i, j, l, k, p, q, r, x, y, u, v, n, m;
    LL *linkedList;
    linkedList = linkedList->createNewNode(1);
    linkedList->next=NULL;
    linkedList->prev=NULL;
    linkedList->addNodeAtEnd(2);
    linkedList->addNodeAtEnd(3);
    linkedList->addNodeAtEnd(4);
    linkedList->addNodeAtEnd(3);
    linkedList->addNodeAtEnd(3);
    linkedList->addNodeAtEnd(5);
    linkedList->print();
    cout << endl;
    linkedList->addNodeAtBegin(13);
    linkedList->addNodeAtBegin(3);
    linkedList->print();
    cout << endl;
    cout << linkedList->length() << endl;
    if (linkedList->Search(6))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    linkedList->Delete(1);
    linkedList->print();
    cout << endl;
//    linkedList->Delete(13);
//    linkedList->print();
//    cout << endl;
//    linkedList->Delete(4);
//    linkedList->print();
//    cout << endl;
//    linkedList->Delete(5);
//    linkedList->print();
//    cout << endl;
//    linkedList->Delete(3);
//    linkedList->print();
////    cout << endl;
//    linkedList->Delete(2);
//    linkedList->print();
//    cout << endl;

    if (linkedList->getNthNode(3))
        cout << linkedList->getNthNode(3)->value << endl;
    else
        cout << "Lenght is lesser than n" << endl;


    cout<<linkedList->count(3)<<endl;

    pair<int,int> minMax=linkedList->minmax();
    cout<<minMax.ff<<" "<<minMax.ss<<endl;
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