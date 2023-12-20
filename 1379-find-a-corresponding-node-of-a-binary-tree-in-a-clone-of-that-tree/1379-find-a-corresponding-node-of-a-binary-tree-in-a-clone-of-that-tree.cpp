/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)
        {
            return 0;
        }
        if(original->val == target->val)
        {
            return cloned;
        }
        TreeNode* result1 = getTargetCopy(original->left,cloned->left,target);
        TreeNode* result2 = getTargetCopy(original->right,cloned->right,target);
        return result1 ? result1 : result2;
    }
};