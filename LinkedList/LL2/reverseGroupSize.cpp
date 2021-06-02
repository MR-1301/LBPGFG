// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    pair< node* ,node* >  solve(node *head,int k,int curr)
    {
        if((head==NULL  or head->next==NULL) or curr>=k)
        {
            return {head,head->next};
        }
        pair<node* , node* >  newHead = solve(head->next,k,curr+1);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    struct node *reverse (struct node *head, int k)
    {
        // Complete this method
        node* toPass=NULL;
        bool flag=true;
        node* prevTail=NULL;
        while(head!=NULL)
        {
            node* temp=head;
            node* currHead=head;
            pair<node*,node*> newHead= solve(head,k,1);
            if(prevTail)
            prevTail->next=newHead.first;
            prevTail=temp;
            if(flag)
            toPass=newHead.first;
            head=newHead.second;
            flag=false;
        }

        return toPass;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin>>t;

    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin>>k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return(0);
}

// } Driver Code Ends