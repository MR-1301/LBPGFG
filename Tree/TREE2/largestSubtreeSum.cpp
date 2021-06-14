// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>

using namespace std;

// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};

// Function to create new tree node.
Node *newNode(int key) {
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to find largest
// subtree sum recursively.
int ans = INT_MIN;

int findLargestSubtreeSum(Node *root) {
    if (!root) {
        return 0;
    }

    int temp = findLargestSubtreeSum(root->left) + findLargestSubtreeSum(root->right) + root->key;
    ans = max(temp, ans);
    return temp;
}

// Driver function
int main() {
    Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}
