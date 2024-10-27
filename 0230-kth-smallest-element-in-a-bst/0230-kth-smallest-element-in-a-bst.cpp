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
    void recursion(TreeNode* root,int& count,int& val,int k){
        if(!root){
            return;
        }
        recursion(root->left,count,val,k);
        if(count==k){
            val = root->val;
        }
        count++;
        recursion(root->right,count,val,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        int count = 1;
        recursion(root,count,val,k);
        return val;
    }
};