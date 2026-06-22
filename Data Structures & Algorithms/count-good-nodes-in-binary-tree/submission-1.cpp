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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        int ans = 1;

        while (!q.empty()) {
            auto [node, mx] = q.front();
            q.pop();
            if (node->left) {
                if (node->left->val >= mx) ans++;
                q.push(make_pair(node->left, max(node->left->val, mx)));
            }
            if (node->right) {
                if (node->right->val >= mx) ans++;
                q.push(make_pair(node->right, max(node->right->val, mx)));
            }
        }
        return ans;
    }
};
