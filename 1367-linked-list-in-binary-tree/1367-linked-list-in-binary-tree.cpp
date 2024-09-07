/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool doesMatch(ListNode* head, TreeNode* root) {
        if (!head) return true; // List is fully traversed.
        if (!root) return false; // Tree path ended but list didn't.

        if (head->val != root->val) return false; // Value mismatch.

        // Recurse down both left and right subtrees for matching path.
        return doesMatch(head->next, root->left) || doesMatch(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
        return true; // If the linked list is fully traversed, return true.
    }
    if (!root) {
        return false; // If the tree node is null and the list isn't done, return false.
    }

    // Helper function to match the subpath from the current root
    

    // Check if the path matches starting from the current node
    if (doesMatch(head, root)) {
        return true;
    }

    // If it doesn't match, check subtrees of the current node
    return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};