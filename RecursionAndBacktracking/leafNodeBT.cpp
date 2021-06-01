#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

// function to print leaf
// nodes from left to right
void printLeafNodes(Node *root) {
    if (!(root->left) and !(root->right)) {
        cout << root->data << " ";
        return;
    }

    if (root->left)
        printLeafNodes(root->left);

    if (root->right)
        printLeafNodes(root->right);
}

// Utility function to create a new tree node
Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main() {
    // Let us create binary tree shown in
    // above diagram

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    printLeafNodes(root);

    return 0;
}