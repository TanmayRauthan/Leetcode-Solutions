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
    ListNode* rotateRight(ListNode* h, int k) {
        ListNode *prev,*cur,*lat,*x,*y;
        cur=h;prev=NULL;
        int n=0;
        while(cur)
        {
            cur=cur->next;
            n++;
        }
        if(n==0)
            return h;
        k=k%n;
        if(k==0||n==0||n==1)
            return h;
        cur=h;
        while(cur)
        {
            lat=cur->next;
            cur->next=prev;
            prev=cur;
            cur=lat;
        }
        cur=prev;
        x=prev;
        prev=NULL;
        for(int i=0;i<k;i++)
        {
            lat=cur->next;
            cur->next=prev;
            prev=cur;
            cur=lat;
        }
        y=prev;
        cur=lat;prev=NULL;
        while(cur)
        {
            lat=cur->next;
            cur->next=prev;
            prev=cur;
            cur=lat;
        }
        x->next=prev;
        return y;
    }
};
