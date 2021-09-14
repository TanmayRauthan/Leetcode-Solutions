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
    ListNode* reverseBetween(ListNode* h, int m, int n) {
        if(m==n)
            return h;
        ListNode *head=h;
        for(int i=1;i<m-1;i++)
        {
            h=h->next;
        }
        ListNode *x;
        if(m>1)
            x=h->next;
        else
            x=h;
        ListNode *y=x;
        ListNode *lat;
        ListNode *prev=NULL;
        int cnt=m;
        while(m<=n)
        {
            lat=x->next;
            x->next=prev;
            prev=x;
            x=lat;
            m++;
        }
        y->next=lat;
        if(cnt>1)
        {
            h->next=prev;
            return head;
        }
        else
        return prev;
    }
};
