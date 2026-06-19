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
    int f(TreeNode* root, bool &ans)
    {
        if(!root) return 0;
        if(!ans) return 0;
        int a = f(root -> left, ans);
        int b = f(root -> right, ans);

        ans &= abs(a - b) <= 1;
        return max(a,b) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = 1;
        f(root, ans);
        return ans;
    }
};
