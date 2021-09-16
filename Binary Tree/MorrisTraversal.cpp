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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        TreeNode *cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                v.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode *prev=cur->left;
                while(prev->right!=NULL&&prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(!prev->right)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    v.push_back(cur->val);
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return v;
    }
};