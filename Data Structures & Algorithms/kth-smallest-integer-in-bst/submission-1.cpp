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
    void f(TreeNode* root, int k, int& rank, int& ans) {
        if (!root) return;
        f(root->left, k, rank, ans);
        rank++;
        if (rank == k) 
        {
            ans = root->val;
            return;
        }
        f(root->right, k, rank, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        int ans = 0;
        f(root, k, rank, ans);
        return ans;
    }
};
