/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* myreverse(ListNode *head,int k,int cnt,int n)
    {
        if(cnt>(n/k)||head==NULL)
            return head;
        ListNode *prev=NULL,*front,*cur=head;
        for(int i=0;i<k;i++)
        {
            front=cur->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
        head->next=myreverse(cur,k,cnt+1,n);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first=head;int n=0;
        while(first!=NULL)
        {
            n++;first=first->next;
        }
        return myreverse(head,k,1,n);
    }
};
