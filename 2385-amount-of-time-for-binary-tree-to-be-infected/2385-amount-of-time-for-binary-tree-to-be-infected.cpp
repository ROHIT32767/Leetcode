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
    int amountOfTime(TreeNode* root, int start) {
                if(!root)
        {
            return 0;
        }
        if(!(root->left) && !(root->right))
        {
            return 0;
        }
        map<TreeNode*,TreeNode*> M;
        TreeNode* Target = root;
        M[root]=0;
        TreeNode* prev = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size())
        {
            int size = Q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* front = Q.front();
                if(front->val==start)
                {
                    Target = front;
                }
                Q.pop();
                if(front->left)
                {
                    M[front->left]=front;
                    Q.push(front->left);
                }
                if(front->right)
                {
                    M[front->right]=front;
                    Q.push(front->right);
                }
            }
        }
        map<int,int> m;
        queue<pair<TreeNode*,int>> BFS;
        BFS.push(make_pair(Target,0));
        m[Target->val]=1;
        // cout << "Target is " << Target << endl;
        long long int max = 0;
        while(BFS.size())
        {
            int size = BFS.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* front = (BFS.front()).first;
                int level = (BFS.front()).second;
                // cout << "Target is " << Target << " Level is " endl;
                if(level>max)
                {
                    max = level;
                }
                BFS.pop();
                if(front->left && !m[front->left->val])
                {
                    m[front->left->val]=1;
                    BFS.push(make_pair(front->left,level+1));
                }
                if(front->right && !m[front->right->val])
                {
                    m[front->right->val]=1;
                    BFS.push(make_pair(front->right,level+1));
                }
                if(M[front] && !m[M[front]->val])
                {
                    m[M[front]->val]=1;
                    BFS.push(make_pair(M[front],level+1));
                }
            }
        }
        return max;
    }
};