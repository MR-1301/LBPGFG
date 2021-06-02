// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
public:
    Node* findMid(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

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

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* mid=findMid(head);
        mid->next= solve(mid->next);
        mid=mid->next;
        while(mid!=NULL)
        {
            if(head->data!=mid->data)
                return false;
            mid=mid->next;
            head=head->next;
        }

        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends