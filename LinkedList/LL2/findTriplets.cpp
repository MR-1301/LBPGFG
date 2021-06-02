
// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
    int data;
    struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.
int pairSum(struct Node *head, int x) {
    if(head==NULL)
        return 0;
    Node *right = head;
    while (right->next != NULL)
        right = right->next;

    Node *left = head;
    int cnt = 0;
    while (left != right and left->prev != right) {
        if (left->data + right->data == x) {
            cnt++;
            left = left->next;
            right = right->prev;
        } else if (left->data + right->data < x) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return cnt;
}

void countTriplets(Node *head,int x) {
    int ans = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        ans+= pairSum(curr->next,x-(curr->data));
    }

    cout << ans<<endl;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data) {
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program
int main() {
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 17;

    countTriplets(head, x);

    return 0;
}