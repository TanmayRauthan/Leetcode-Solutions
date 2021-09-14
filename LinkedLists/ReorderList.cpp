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
    void reorderList(ListNode* head) {
        ListNode* s=head,*f=head;
        //find mid of list
        while(f!=NULL&&f->next!=NULL)
        {
            s=s->next;
            f=(f->next)->next;
        }
        //reverse list from mid next 
        ListNode *mid=s;
        ListNode *cur,*nxt,*prev;
        cur=mid->next;
        mid->next=NULL;
        prev=NULL;
        while(cur!=NULL)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        //merge both list alternatively
        s=head;
        while(prev!=NULL)
        {
            nxt=s->next;
            s->next=prev;
            prev=prev->next;
            s->next->next=nxt;
            s=nxt;
        }
    }
};
