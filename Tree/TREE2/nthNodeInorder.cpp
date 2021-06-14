#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
  
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node =
          (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return (node);
}
  
/* Given a binary tree, print its nth nodes of inorder*/

void NthInorder(struct Node* node, int n)
{
    static int count=0;
    if(!node)
        return;

    if(count<=n)
    {
        NthInorder(node->left,n);

        count++;
        if(count==n)
        cout<<node->data<<endl;

        NthInorder(node->right,n);
    }
}
  
/* Driver program to test above functions*/
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
  
    int n = 4;
  
    NthInorder(root, n);
    return 0;
}