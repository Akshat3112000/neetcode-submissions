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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p) return 0;
        if(!q) return 0;

        if(p -> val == q -> val) return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return 1;
        if(!root) return 0;
        if(isSameTree(root, subRoot)) return 1;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
