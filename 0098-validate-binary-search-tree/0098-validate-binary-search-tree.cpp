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
    pair<long long,long long> recursion(TreeNode* root,bool& flag){
        pair<int,int> left,right;
        left = make_pair(root->val,root->val);
        right = make_pair(root->val,root->val);
        bool flag1 = true;
        bool flag2 = true;
        if(root->left){
            left = recursion(root->left,flag);
            if(root->val<=left.second){
                flag1 = false;
            }
        }
        if(root->right){
            right = recursion(root->right,flag);
            if(root->val>=right.first){
                flag2 = false;
            }
        }
        if(!flag1 || !flag2){
            flag = flag1 && flag2;
        }
        return make_pair(min(left.first,root->val),max(root->val,right.second));
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!(root->left)&&!(root->right)){
            return true;
        }
        bool flag = true;
        recursion(root,flag);
        return flag;
    }
};