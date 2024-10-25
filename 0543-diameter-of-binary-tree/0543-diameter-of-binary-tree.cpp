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
    int width(TreeNode* root,int& MAX){
        if(!root){
            return 0;
        }
        int left = width(root->left,MAX);
        int right = width(root->right,MAX);
        MAX = max(1+left+right,MAX);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int MAX = 1;
        width(root,MAX);
        return MAX-1;
    }
};