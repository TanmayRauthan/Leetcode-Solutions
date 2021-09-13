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
    ListNode* removeNthFromEnd(ListNode* h, int n) {
       ListNode *f,*s;
       s=h,f=h;
       while(n--)
       {
           f=f->next;
       }
       if(!f)
           return h->next;
       while(f->next)//When f will reach end s will reach previous of node to be deleted(simple maths number line)
       {
           f=f->next;
           s=s->next;
       }
       ListNode* temp=s->next;
       s->next=temp->next;
       //free(temp);
       return h; 
    }
};
