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
    bool checkIdentical(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        else if(!p || !q){
            return false;
        }
        return (p->val==q->val) && checkIdentical(p->left,q->right) && checkIdentical(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return checkIdentical(root->left,root->right);
    }
};