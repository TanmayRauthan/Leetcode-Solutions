/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        if(!h)
            return NULL;
        unordered_map<int,Node*> pm;
        unordered_map<Node*,int> rm;
        Node* z=h;
        Node *x=new Node(0);
        x->val=h->val;
        Node* y=x;
        int pos=1;
        pm[pos]=x;
        rm[h]=pos;
        while(h->next)
        {
            x->next=new Node(0);
            (x->next)->val=(h->next)->val;
            x=x->next;
            h=h->next;
            pos++;
            pm[pos]=x;
            rm[h]=pos;
        }
        h=z;
        x=y;
        pos=1;
        while(h)
        {
            x->random=pm[rm[h->random]];
            x=x->next;
            h=h->next;
            pos++;
        }
        return y;
    }
};
