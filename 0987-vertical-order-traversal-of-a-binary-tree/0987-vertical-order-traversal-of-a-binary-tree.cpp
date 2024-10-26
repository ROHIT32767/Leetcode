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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<pair<int,int>,vector<int>> M;
        queue<pair<TreeNode*,int>> Q;
        Q.push(make_pair(root,0));
        int index = 0;
        while(!Q.empty()){
            int size = Q.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*,int> front = Q.front();
                Q.pop();
                TreeNode* temp = front.first;
                int column = front.second;
                M[make_pair(column,index)].push_back(temp->val);
                if(temp->left){
                    Q.push(make_pair(temp->left,column-1));
                }
                if(temp->right){
                    Q.push(make_pair(temp->right,column+1));
                }
            }
            index++;
        }
        map<int,vector<int>> dist;
        for(auto i:M){
            vector<int> vect = i.second;
            sort(vect.begin(),vect.end());
            for(int j=0;j<vect.size();j++){
                dist[i.first.first].push_back(vect[j]);
            }
        }
        for(auto k:dist){
            ans.push_back(k.second);
        }
        return ans;
    }
};