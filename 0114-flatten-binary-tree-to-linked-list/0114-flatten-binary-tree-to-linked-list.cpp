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
    void f(TreeNode* root, queue<TreeNode*>& q) {
        if(root != nullptr) {
            q.push(root);
            f(root->left, q);
            f(root->right, q);
        }
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        f(root, q);

        TreeNode* tail = q.front(); //root node assign
        q.pop();

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            tail->left = nullptr;
            tail->right = node;
            tail = node;
        }


    }
};