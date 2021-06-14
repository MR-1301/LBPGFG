// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



// } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/


class Solution {
public:
    /*You are required to complete below method */
    int evalTree(node *root) {
        // Your code here
        if (root == NULL)
            return 0;

        if (!root->left and !root->right)
            return stoi(root->data);

        int l = evalTree(root->left);
        int r = evalTree(root->right);

        if (root->data == "+")
            return l + r;
        if (root->data == "-")
            return l - r;
        if (root->data == "*")
            return ((l != 0) ? l : 0) * ((r != 0) ? r : 0);
        if (root->data == "/")
            return ((l != 0) ? l : 0) / ((r != 0) ? r : 1);

        return 0;
    }
};


// { Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
// } Driver Code Ends