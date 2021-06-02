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
Node* removeDuplicates(Node *root);
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
        Node *head = NULL;
        Node *temp = head;

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

        Node *result  = removeDuplicates(head);
        print(result);
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node* temp=head;
    Node* prev=temp;
    temp=temp->next;
    while(temp!=NULL)
    {
        if(temp->data==prev->data)
        {
            prev->next=temp->next;
            free(temp);
        }
        else{
            prev=temp;
        }
        temp=prev->next;
    }
    return head;
}