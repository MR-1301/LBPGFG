// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head)
    {
        Node* temp=head;
        Node* prev=temp;
        unordered_set<int> s;
        s.insert(temp->data);
        temp=temp->next;
        while(temp!=NULL)
        {
            if(s.find(temp->data)!=s.end())
            {
                prev->next=temp->next;
                free(temp);
            }
            else{
                s.insert(temp->data);
                prev=temp;
            }
            temp=prev->next;
        }
        return head;
    }
};


// { Driver Code Starts.

int main() {
    // your code goes here
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0;i<K;i++){
            int data;
            cin>>data;
            if(head==NULL)
                head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }

        Solution ob;
        Node *result  = ob.removeDuplicates(head);
        print(result);
        cout<<endl;

    }
    return 0;
}  // } Driver Code Ends