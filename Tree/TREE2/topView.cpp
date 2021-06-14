// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

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

//test for
//1
//23 17 65 9 19 38 69 7 10 18 21 37 43 67 74 1 8 N 14 N N 20 22 33 N 39 53 66 68 70 N N 4 N N 13 16 N N N N 29 35 N 40 51 62 N N N N N 71 3 5 11 N 15 N 27 32 34 36 N 41 45 52 58 63 N 72 2 N N 6 N 12 N N 24 28 30 N N N N N N 42 44 47 N N 57 61 N 64 N 73 N N N N N N N 26 N N N 31 N N N N 46 49 55 N 60 N N N N N 25 N N N N N 48 50 54 56 59

class Solution
{
    public:
    map<int,pair<int,int> > mp;

    void solve(Node* root,int curr,int level)
    {
        if(!root)
            return;

        solve(root->left,curr-1,level+1);
        solve(root->right,curr+1,level+1);

        //doubt
        if(mp.find(curr)==mp.end() or mp[curr].second>level)
        mp[curr]={root->data,level};

    }

    vector<int> topView(Node *root)
    {
        //Your code here

        solve(root,0,0);

        vector<int> res;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
            res.push_back(itr->second.first);
        return res;
    }

};



// { Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends