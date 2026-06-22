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
    unordered_map<TreeNode*,int> a,b;
    int f(TreeNode* root)
    {
        if(!root) return 0;
        if(a.find(root) != a.end()) return a[root];
        return a[root] = root -> val + max(0,max(f(root -> left),f(root -> right)));
    }
    int g(TreeNode* root) {
        if(!root) return 0;
        if(b.find(root) != b.end()) return b[root];
        int ans = max(g(root -> left), g(root -> right));
        ans = max(ans, max(0,f(root -> left)) + root -> val + max(0,f(root -> right)));
        return b[root] = ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        int ans = g(root);
        if(ans == 0)
        {
            ans = INT_MIN;
            for(pair<TreeNode* const,int>& x:a)
            {
                ans = max(ans,x.second);
            }
        }
        return ans;
    }
};
