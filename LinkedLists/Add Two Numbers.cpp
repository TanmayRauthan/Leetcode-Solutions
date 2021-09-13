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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0; 
        ListNode *l3;
        ListNode f(0);
        l3=&f;
        while(l1&&l2)
        {
            l3->next=l1;
            l3=l3->next;
            int z=l1->val;
            l3->val=(l1->val + l2->val +c)%10;
            c=(z+l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            l3->next=l1;
            l3=l3->next;
            int z=l1->val;
            l3->val=(l1->val+c)%10;  
            c=(z+c)/10;
            l1=l1->next;
        }
        while(l2)
        {
            l3->next=l2;
            l3=l3->next;
            int z=l2->val;
            l3->val=(l2->val+c)%10;
            c=(z+c)/10;  
            l2=l2->next;
        }
        if(c==1)
        {
          
           l3->next= new ListNode(c);
        }
        else
        {
            l3->next=NULL;
        }
        return f.next;
    }
};
