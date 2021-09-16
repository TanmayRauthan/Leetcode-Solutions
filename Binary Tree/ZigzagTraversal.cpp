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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        vector<vector<int>> ans;
        vector<int> v;
        if(root==NULL)
            return ans;
        s1.push(root);
        while(!s1.empty()||!s2.empty())
        {
            while(!s1.empty())
            {
                TreeNode* front=s1.top();//cout<<front->val<<" ";
                s1.pop();
                v.push_back(front->val);
                if(front->left)
                    s2.push(front->left);
                if(front->right)
                    s2.push(front->right);
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
            while(!s2.empty())
            {
                TreeNode* front=s2.top();
                s2.pop();
                v.push_back(front->val);
                if(front->right)
                    s1.push(front->right);
                if(front->left)
                    s1.push(front->left);
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};
