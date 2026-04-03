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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> v;
        queue<TreeNode*> q;

        if(root == nullptr) {
            return true;
        }

        if(root && !root->left && !root->right) {
            return true;
        }

        q.push(root->left);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            v.push_back(node);

            if(node) {
                q.push(node->right);
                q.push(node->left);
            }
            
        }

        q.push(root->right);
        int i = 0;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* mirrorNode = v[i++];

            if(!node && !mirrorNode) continue;
            if(!node || !mirrorNode || node->val != mirrorNode->val) {
                return false;
            }

            if(node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};