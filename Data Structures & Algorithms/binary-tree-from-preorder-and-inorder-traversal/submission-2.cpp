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
    unordered_map<int, int> idx;
    TreeNode* f(vector<int>& pre, int sz, int i, int j) {
        if (sz == 0) return nullptr;
        TreeNode* root = new TreeNode(pre[i]);
        int m = idx[pre[i]];
        root->left = f(pre, m - j, i + 1, j);
        root->right = f(pre, j + sz - 1 - m, i - j + m + 1, m + 1);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            idx[inorder[i]] = i;
        }
        return f(preorder, n, 0, 0);
    }
};
