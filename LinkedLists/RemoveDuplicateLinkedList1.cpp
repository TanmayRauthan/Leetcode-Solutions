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
        ListNode *f=h;
        while(h)
        {
            ListNode *x=h;
            while(x->next!=NULL&&(x->val)==((x->next)->val))
                x=x->next;
            h->next=x->next;
            h=h->next;
        }
        return f;
    }
};
