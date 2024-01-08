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
    void recursion(TreeNode* root,int low,int high,int& count){
        if(!root){
            return;
        }
        if(root->val>=low && root->val<=high){
            count+=root->val;
            recursion(root->left,low,root->val,count);
            recursion(root->right,root->val,high,count);
        }
        else if(root->val<low){
            recursion(root->right,low,high,count);
        }
        else{
            recursion(root->left,low,high,count);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count = 0;
        recursion(root,low,high,count);
        return count;
    }
};