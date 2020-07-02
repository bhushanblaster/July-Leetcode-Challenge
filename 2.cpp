/*
Binary Tree Level Order Traversal II

Solution
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       
        vector<vector<int>>vec;
        if(!root)
            return vec;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            while(sz--)
            {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            vec.push_back(temp);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
