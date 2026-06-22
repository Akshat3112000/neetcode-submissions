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
    bool isValidBST(TreeNode* root) {
        if (!root) return 1;
        bool b = 1;
        TreeNode* cur;

        if (root->left) {
            cur = root->left;
            while (cur->right) cur = cur->right;
            b &= (cur->val < root->val);
        }
        if (root->right) {
            cur = root->right;
            while (cur->left) cur = cur->left;
            b &= (cur->val > root->val);
        }

        return b && isValidBST(root->left) && isValidBST(root->right);
    }
};
