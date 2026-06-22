class Solution {
private:
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        // 1. Check Left Subtree
        if (!isValidBST(root->left)) return false;
        
        // 2. Check Current Node
        if (prev && root->val <= prev->val) return false;
        prev = root; // Update the previously seen node
        
        // 3. Check Right Subtree
        return isValidBST(root->right);
    }
};