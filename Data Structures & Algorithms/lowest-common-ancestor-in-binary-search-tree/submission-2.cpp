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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val > q -> val) return lowestCommonAncestor(root, q, p);
        TreeNode* cur = root;
        while(cur){
            if(cur -> val < p -> val) cur = cur -> right;
            else if(cur -> val > q -> val) cur = cur -> left;
            else return cur;
        }

        return root;
    }
};
