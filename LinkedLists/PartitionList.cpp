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
    ListNode* partition(ListNode* h, int xa) {
        ListNode *temp=new ListNode(-1);
        ListNode *p=new ListNode(-1);
        ListNode *x,*y;
        x=temp;y=p;
        while(h)
        {
            if(h->val<xa)
            {
                temp->next=h;
                temp=temp->next;
            }
            else
            {
                p->next=h;
                p=p->next;
            }
            h=h->next;
        }
        p->next=NULL;
        temp->next=y->next;
        return x->next;
    }
};
