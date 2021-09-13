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
    ListNode* merge(ListNode *a,ListNode*b)
    {
        if(a==NULL&&b==NULL)
            return NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->val<=b->val)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int i,j,n=v.size();
        if(n==0)
            return NULL;
        i=0,j=n-1;
        while(j!=0)
        {
            i=0;
            int l=j;
            while(i<l)
            {
                v[i]=merge(v[i],v[l]);
                i++;
                l--;
                if(i>=l)
                {
                    j=l;
                }   
            }
        }
        return v[0];
    }
};
