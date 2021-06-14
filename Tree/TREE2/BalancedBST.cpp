/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeBSTTreeNodes(TreeNode *root, vector<TreeNode *> &TreeNodes) {
    // Base case
        if (root == nullptr)
            return;

        // Store TreeNodes in Inorder (which is sorted
        // order for BST)
        storeBSTTreeNodes(root->left, TreeNodes);
        TreeNodes.push_back(root);
        storeBSTTreeNodes(root->right, TreeNodes);
    }

    /* Recursive function to construct binary tree */
    TreeNode *buildTreeUtil(vector<TreeNode *> &TreeNodes, int start,
                        int end) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;

        TreeNode *TreeNode = TreeNodes[mid];
        TreeNode->left = buildTreeUtil(TreeNodes, start, mid - 1);
        TreeNode->right = buildTreeUtil(TreeNodes, mid + 1, end);
        return TreeNode;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> TreeNodes;
        storeBSTTreeNodes(root, TreeNodes);

        // Constucts BST from TreeNodes[]
        int n = TreeNodes.size();
        return buildTreeUtil(TreeNodes, 0, n - 1);
    }
};