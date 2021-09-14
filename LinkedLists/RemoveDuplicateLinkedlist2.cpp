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
    ListNode* deleteDuplicates(ListNode* h) {
        ListNode *x,*y,*temp;
        temp=new ListNode(0);
        x=temp;
        while(h)
        {
            int cnt=0;
            while(h->next&&h->val==(h->next)->val)
            {
                h=h->next;
                cnt++;
            }
            if(cnt==0)
            {
                temp->next=h;
                temp=temp->next;
            }
            h=h->next;
        }
        temp->next=NULL;
        return x->next;
    }
};
