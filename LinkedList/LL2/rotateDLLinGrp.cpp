#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push(Node** head_ref, Node* new_node)
{
    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node* temp=head;
    int cnt=1;
    Node* prevTail=NULL;
    Node* toPass=head;
    bool flag= true;
    Node* prev;
    while(temp!=NULL)
    {
        Node* currHead=temp;
        while(temp!=NULL and cnt!=k+1)
        {
            cnt++;
            prev=temp;
            Node* lol=temp->next;
            swap(temp->prev,temp->next);
            temp=lol;
        }

        Node* newHead=prev;
        newHead->prev= prevTail;
        if(prevTail!=NULL)
        prevTail->next=newHead;
        prevTail=currHead;

        if(flag)
            toPass=newHead;
        flag= false;
        cnt=1;
    }
    prevTail->next=NULL;
    return toPass;
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    push(&head, getNode(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);
    cout<<endl;
    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}