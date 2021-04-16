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
   
    vector<TreeNode*> solve(int s,int e)
    {
        vector<TreeNode*> res;
        if(s>e)
            res.push_back(0);
        else if(s==e)
            res.push_back(new TreeNode(s));
        else
        {
            for(int i=s;i<=e;i++)
            {
                vector<TreeNode*> l=solve(s,i-1);
                vector<TreeNode*> r=solve(i+1,e);
                for(int j=0;j<l.size();j++)
                {
                    for(int k=0;k<r.size();k++)
                    {
                        TreeNode *root=new TreeNode(i);
                        root->left=l[j];
                        root->right=r[k];
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> x;
        if(n==0)
            return x;
        return solve(1,n);
    }
};
