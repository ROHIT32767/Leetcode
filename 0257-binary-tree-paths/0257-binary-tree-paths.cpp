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
    void backtrack(TreeNode* root,vector<string>& vect,string& s)
    {
        int size = s.size();
        if(!root)
        {
            return;
        }
        if(!(root->left) && !(root->right))
        {
            s= s+to_string(root->val);
            vect.push_back(s);
            s = s.substr(0,size);
            return;
        }
        s+=to_string(root->val);
        s+="->";
        backtrack(root->left,vect,s);
        s = s.substr(0,size);
        s+=to_string(root->val);
        s+="->";
        backtrack(root->right,vect,s);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
        {
            return vector<string>{};
        }
        string s = "";
        vector<string> vect;
        if(!(root->left) && !(root->right))
        {
            s = to_string(root->val);
            vect.push_back(s);
            return vect;
        }
        backtrack(root,vect,s);
        return vect;
    }
};