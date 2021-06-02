#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void moveToFront(Node **head_ref)
{
    Node* temp=*head_ref;
    Node* prev=temp;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    prev->next=NULL;
    temp->next=*head_ref;
    *head_ref=temp;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Driver code */
int main()
{
    Node *start = NULL;

    /* The constructed linked list is: 
    1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout<<"Linked list before moving last to front\n";
    printList(start);

    moveToFront(&start);

    cout<<"\nLinked list after removing last to front\n";
    printList(start);

    return 0;
} 