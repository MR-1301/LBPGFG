class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        if(length==1 or k==0)
            return head;
        k=k%length;
        int n=length-k;

        if(length==1 or k==0)
            return head;

        temp=head;
        while(n-- and temp!=NULL)
        {
            temp=temp->next;
        }

        ListNode* currHead=head;
        head=temp;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=currHead;
        temp=currHead;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};