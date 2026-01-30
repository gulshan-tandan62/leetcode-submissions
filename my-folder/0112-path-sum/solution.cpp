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
    bool pathSum(TreeNode* root,int sum,int targetSum)
    {
        if(!root) return false;
        sum+= root->val;
        if(!root->left && !root->right) return sum == targetSum;
        return pathSum(root->left,sum,targetSum)||pathSum(root->right,sum,targetSum);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //if(!root) return false;
        return pathSum(root,0,targetSum);
    }
};
