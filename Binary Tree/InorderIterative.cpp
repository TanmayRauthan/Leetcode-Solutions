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
        stack<TreeNode *> s;
        TreeNode *cur=root;
        while(cur!=NULL||!s.empty())
        {
            while(cur!=NULL)
            {
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            v.push_back(cur->val);
            s.pop();
            cur=cur->right;
        }
        return v;
    }
};
