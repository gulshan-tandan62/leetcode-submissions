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
    int prev = -1;
    int mindiff = INT_MAX;
public: 
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev!=-1)
        {
            mindiff = min(mindiff,abs(prev-root->val));
        }
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mindiff;
    }
};
