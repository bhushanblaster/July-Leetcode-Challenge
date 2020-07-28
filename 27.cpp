/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
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
    TreeNode* construct(int inst,int inend,int postart,int poend,vector<int>& inorder, vector<int>& postorder)
    {
        int data = postorder[poend];
        TreeNode* root = new TreeNode(data);
        
        for(int i = inst;i<=inend;i++)
        {
          if(inorder[i] == data)
          {
              if(i==inst)
              {
                  root->left = NULL;
              }
              else
              {
                  root->left = construct(inst,i-1,postart,postart+(i-inst-1),inorder,postorder);
              }
              if(i==inend)
              {
                  root->right = NULL;
              }
              else
              {
                  root->right = construct(i+1,inend,poend-1-(inend-i-1),poend-1,inorder,postorder);
              }
          }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(n==0)
            return NULL;
        return construct(0,n-1,0,n-1,inorder,postorder);
    }
};
