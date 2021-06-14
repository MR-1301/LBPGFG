// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>

using namespace std;

// structure of a node of BST
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

void insert(Node **tree, int val) {
    Node *temp = NULL;
    if (!(*tree)) {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if (val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node *root1, Node *root2, int x);

// Driver code
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int T;
    cin >> T;
    while (T--) {
        Node *root1 = NULL;
        Node *root2 = NULL;
        int n1, n2, k;
        cin >> n1;
        for (int i = 0; i < n1; i++) {
            cin >> k;
            insert(&root1, k);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++) {
            cin >> k;
            insert(&root2, k);
        }
        int s;
        cin >> s;
        cout << countPairs(root1, root2, s) << "\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function


int countPairs(Node *root1, Node *root2, int x) {
    int count = 0;
    stack<Node *> a, b;

    while (root1 != NULL) {
        a.push(root1);
        root1 = root1->left;
    }
    while (root2 != NULL) {
        b.push(root2);
        root2 = root2->right;
    }

    while (!a.empty() and !b.empty()) {
        if (a.top()->data + b.top()->data == x) {
            count++;
            Node *root = a.top();
            a.pop();
            root = root->right;
            while (root != NULL) {
                a.push(root);
                root = root->left;
            }

            root = b.top();
            b.pop();
            root = root->left;
            while (root != NULL) {
                b.push(root);
                root = root->right;
            }
        } else if (a.top()->data + b.top()->data < x) {
            Node *root = a.top();
            a.pop();
            root = root->right;
            while (root != NULL) {
                a.push(root);
                root = root->left;
            }
        } else {
            Node *root = b.top();
            b.pop();
            root = root->left;
            while (root != NULL) {
                b.push(root);
                root = root->right;
            }
        }
    }

    return count;
}