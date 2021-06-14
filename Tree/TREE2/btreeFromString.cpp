#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *newNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

unordered_map<int, int> mp;

void preProcess(string str) {
    stack<pair<char, int>> s;
    for (int i = 0; i < str.length(); i++) {
        if (s.empty() or str[i] == '(')
            s.push({str[i], i});
        else if (str[i] == ')')
        {
            mp[s.top().second]=i;
            s.pop();
        }
    }
}

Node *treeFromString(string str, int si, int ei) {
    if (si > ei)
        return NULL;

    if (si == ei)
        return new Node(str[si] - '0');

    Node *root = new Node(str[si] - '0');

    if (si + 1 <= ei and str[si + 1] == '(')
        root->left = treeFromString(str, si + 2, mp[si + 1] - 1);
    if(mp[si+1]+1<=ei and str[mp[si+1]+1]=='(')
        root->right= treeFromString(str,mp[si+1]+2,mp[mp[si+1]+1]-1);

    return root;
}

// Driver Code
int main() {
    string str = "1(2()(4))(3)";
    mp.clear();
    preProcess(str);
    Node *root = treeFromString(str, 0, (int) str.length() - 1);
    preOrder(root);
}