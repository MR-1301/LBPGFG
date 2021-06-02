// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size) {
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    int length(Node *head) {
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    Node *solve(Node *head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        Node *newHead = solve(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    void print(Node* head) {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second) {
        // code here
        if (length(first) < length(second))
        {
            Node* temp=first;
            first=second;
            second=temp;
        }

        first = solve(first);
        second = solve(second);

        Node* a=first;
        Node* b=second;
        int carry=0;
        Node* prevA;
        while(a!=NULL)
        {
            if(b==NULL)
            {
                int lol=(a->data+carry);
                a->data=lol%10;
                carry=lol/10;
            }
            else{
                int lol=(a->data+b->data+carry);
                a->data=lol%10;
                carry=lol/10;
                b=b->next;
            }
            prevA=a;
            a=a->next;
        }
        if(carry>0)
        {
            prevA->next=new Node(carry);
        }

        first= solve(first);
        return first;
    }
};


// { Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends