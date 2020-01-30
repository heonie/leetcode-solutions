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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        inorder(traversal, root);
        return traversal;
    }
    void inorder(vector<int> &traversal, TreeNode *root) {
        if(root == NULL) {
            return;
        }
        inorder(traversal, root->left);
        traversal.push_back(root->val);
        inorder(traversal, root->right);
    }
};
