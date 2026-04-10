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
    bool f(TreeNode* root, long long minRange, long long maxRange) {
        if(root == nullptr) {
            return true;
        }
        if(root->val <= minRange || root->val >= maxRange) {
            return false;
        }

        bool lefside = f(root->left, minRange, root->val);
        bool rightside = f(root->right, root->val, maxRange);

        return lefside && rightside;
    }

    bool isValidBST(TreeNode* root) {
        return f(root, LLONG_MIN, LLONG_MAX);
    }
};