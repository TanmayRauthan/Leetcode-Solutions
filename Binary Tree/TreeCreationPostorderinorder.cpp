/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i;
    unordered_map<int,int> m;
    TreeNode* solve(vector<int> p, vector<int>& in,int l,int r)
    {
        if(l>r)
            return NULL;
        if(l==r)
        {
            TreeNode *x=new TreeNode(p[i]);
            i--;
            return x;
        }
        TreeNode *root=new TreeNode(p[i]);
        int ind=m[p[i]];
        i--;
        root->right=solve(p,in,ind+1,r);
        root->left=solve(p,in,l,ind-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        for(int i=0;i<p.size();i++)
            m[in[i]]=i;
        i=p.size()-1;
        return solve(p,in,0,p.size()-1);
    }
};
