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
    TreeNode* f(vector<int>& pre, unordered_map<int,int>& idx, int sz, int i, int j)
    {
        if(sz == 0) return nullptr;
        TreeNode* root = new TreeNode(pre[i]);
        int m = idx[pre[i]];
        root -> left = f(pre, idx, m - j, i+1, j);
        root -> right = f(pre, idx, j + sz - 1 - m, i - j + m + 1, m + 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> idx;
        for(int i = 0;i < n;i++)
        {
            idx[inorder[i]] = i;
        }
        return f(preorder, idx, n, 0, 0);
    }
};
