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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(!node)
            {
                ans+="NULL#";
                continue;
            }

            ans += to_string(node->val) + "#";

            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;
        int n = data.size();

        for(int i = 0; i < n;i++)
        {
            string s = "";
            while(data[i] != '#')
            {
                s+=data[i];
                i++;
            }
            if(s == "NULL")
            {
                v.push_back(nullptr);
            }
            else
            {
                v.push_back(new TreeNode(stoi(s)));
            }
        }

        int x = 0;
        n = v.size();
        for(int i = 0; i < n; i++)
        {
            if(!v[i]) x-=2;
            else
            {
                v[i] -> left = v[2*i + 1 + x];
                v[i] -> right = v[2*i + 2 + x];
            }
        }
        return v[0];
    }
};
