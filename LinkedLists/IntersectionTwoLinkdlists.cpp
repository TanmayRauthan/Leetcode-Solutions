/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *p=a,*q=b;
        int one=0,two=0;
        while(p!=NULL)
        {
            one++;
            p=p->next;
        }
        while(q!=NULL)
        {
            two++;
            q=q->next;
        }
        if(one>two)
        {
            ListNode* temp=a;
            a=b;
            b=temp;
        }
        two=abs(two-one);
        q=b;
        while(two--)
            q=q->next;
        p=a;
        while(p!=NULL&&q!=NULL)
        {
            if(p==q)
                return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};
