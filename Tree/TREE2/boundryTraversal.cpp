// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int> ans;

    void leftBou(Node *root) {
        if (!root)
            return;

        if (!root->left and !root->right)
            return;

        ans.push_back(root->data);

        if (root->left)
            leftBou(root->left);
        else if (root->right)
            leftBou(root->right);
    }

    void leaves(Node *root) {
        if(!root)
            return;

        if (!root->left and !root->right) {
            ans.push_back(root->data);
            return;
        }

        leaves(root->left);
        leaves(root->right);
    }

    void rightBou(Node *root) {
        if (!root)
            return;

        if (!root->left and !root->right)
            return;

        if (root->right)
            rightBou(root->right);
        else if (root->left)
            rightBou(root->left);

        ans.push_back(root->data);
    }

    vector<int> printBoundary(Node *root) {
        ans.clear();
        ans.push_back(root->data);
        leftBou(root->left);
        leaves(root);
        rightBou(root->right);
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends