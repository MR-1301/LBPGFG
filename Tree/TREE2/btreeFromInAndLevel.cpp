// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n);

void printPreorder(Node *node) {
    if (node == NULL)
        return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}

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
        int in[n], level[n];
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> level[i];
        }
        Node *root = NULL;
        root = buildTree(in, level, 0, n - 1, n);
        printPreorder(root);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
unordered_map<int, int> mp;

Node *solve(int *in, int l, int r) {
    if (l > r)
        return NULL;

    if (l == r)
        return new Node(in[l]);

    int index = -1;
    int mini = INT_MAX;
    for (int i = l; i <= r; i++) {
        if (mp[in[i]] < mini) {
            mini = mp[in[i]];
            index = i;
        }
    }

    Node *root = new Node(in[index]);

    root->left = solve(in, l, index - 1);
    root->right = solve(in, index + 1, r);

    return root;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n) {
    mp.clear();
    int i;
    for (i = 0; i < n; i++)
        mp[levelOrder[i]] = i;

    return solve(inorder,iStart,iEnd);
}