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
    ListNode* swapPairs(ListNode* h) {
        if(!h||h->next==NULL)
            return h;
        ListNode* x=h->next;
        h->next=swapPairs(x->next);
        x->next=h;
        return x;
    }
};
