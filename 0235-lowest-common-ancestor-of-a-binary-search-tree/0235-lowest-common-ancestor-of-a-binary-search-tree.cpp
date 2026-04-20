/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* current = root;
        while (current != NULL) {
            // Both nodes are in the right subtree
            if (p->val > current->val && q->val > current->val) {
                current = current->right;
            } 
            // Both nodes are in the left subtree
            else if (p->val < current->val && q->val < current->val) {
                current = current->left;
            } 
            // Found the split point or one of the nodes
            else {
                return current;
            }
        }
        return NULL;
    }
};