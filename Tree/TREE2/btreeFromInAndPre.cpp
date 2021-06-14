// { Driver Code Starts
//

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    Node *solve(int *in, int l, int r, int *pre, int index) {
        if (l > r)
            return NULL;

        if (r - l == 0)
            return new Node(in[l]);

        int x = pre[index];
        int mid = l, i;
        for (i = l; i <= r; i++) {
            if (in[i] == x) {
                mid = i;
                break;
            }
        }

        Node *node = new Node(x);
        node->left = solve(in, l, mid - 1, pre, index + 1);
        node->right = solve(in, mid + 1, r, pre, index + mid - l + 1);

        return node;
    }

    Node *buildTree(int in[], int pre[], int n) {
        return solve(in, 0, n-1, pre, 0);
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

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends