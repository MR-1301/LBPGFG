// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> maxSumHelper(Node *root) {
    if (!root) {
        return {0, 0};
    }

    pair<int, int> s, s1, s2;
    s1 = maxSumHelper(root->left);
    s2 = maxSumHelper(root->right);

    //root itself is included so we can't include two of it's children
    s.first=s1.second+s2.second+root->data;

    //we are not including root so we can include it's children
    s.second=max(s1.first,s1.second)+max(s2.first,s2.second);

    return s;

}

int maxSum(Node *root) {
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

// Driver code
int main() {
    Node *root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    cout << maxSum(root);
    return 0;
}
