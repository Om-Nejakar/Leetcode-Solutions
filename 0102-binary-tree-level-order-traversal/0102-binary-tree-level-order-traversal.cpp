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
    void solve(TreeNode* root, queue<TreeNode*>& q, vector<vector<int>>& ans, vector<int>& v) {
        while(!q.empty()) {
            v.clear();
            int queueSize = q.size();

            for(int i=0; i<queueSize; i++) {
                TreeNode* x = q.front();
                q.pop();

                if(x->left != nullptr) {
                    q.push(x->left);
                    v.push_back(x->left->val);
                }
                if(x->right != nullptr) {
                    q.push(x->right);
                    v.push_back(x->right->val);
                }
            }

            if(v.size() != 0) {
                ans.push_back(v);
            }

        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;

        if(root == nullptr) {
            return {};
        }

        q.push(root);
        v.push_back(root->val);
        ans.push_back(v);

        solve(root, q, ans, v);
        return ans;
    }
};