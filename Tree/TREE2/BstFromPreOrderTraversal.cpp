//Method-1: O(n^2)
class Solution {
public:
    TreeNode* solve(vector<int> &p,int l,int r)
    {
        if(l>r)
            return NULL;

        if(l==r)
            return new TreeNode(p[l]);

        TreeNode* node=new TreeNode(p[l]);
        int val=p[l++];
        int temp=l;
        while(l<p.size() and p[l]<val)
            l++;

        node->left=solve(p,temp,l-1);
        node->right=solve(p,l,r);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return solve(preorder,0,n-1);
    }
};

//Method-2: O(n)
class Solution {
public:
    TreeNode* solve(vector<int> &p,int *i,int l,int r)
    {
        if(*i>=p.size())
            return NULL;

        if(p[*i]<l or p[*i]>r)
            return NULL;

        TreeNode* node=new TreeNode(p[*i]);
        *i=*i+1;

        node->left=solve(p,i,l,node->val);
        node->right=solve(p,i,node->val+1,r);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int i=0;
        return solve(preorder,&i,INT_MIN,INT_MAX);
    }
};