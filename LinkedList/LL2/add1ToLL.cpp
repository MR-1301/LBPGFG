// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node* neaxt;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node* solve(Node *head)
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }

        Node* newHead=solve(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    Node* addOne(Node *head)
    {
        head= solve(head);
        int carry=1;
        int lol;
        Node* temp=head;
        Node* prev;
        while(carry!=0 and temp!=NULL)
        {
            lol=(temp->data+carry)/10;
            temp->data=(temp->data+carry)%10;
            carry=lol;
            prev=temp;
            temp=temp->next;
        }

        if(carry>0)
        {
            prev->next=new Node(carry);
        }

        head= solve(head);
        return head;
    }
};

// { Driver Code Starts.

int main()
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
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends