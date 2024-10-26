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
    TreeNode* BST(vector<int>& nums,int start,int end){
        if(start>end || start<0 || end>=nums.size()){
            return 0;
        }
        int mid = (start+end)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = BST(nums,start,mid-1);
        temp->right = BST(nums,mid+1,end);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
};