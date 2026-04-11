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
    bool f(TreeNode* root, unordered_map<int, bool>& hp, int k) {
        if(root == nullptr) {
            return false;
        }

        if(hp.find(k-root->val) != hp.end()) {
            return true;
        }else {
            hp[root->val] = true;
        }

        bool left = f(root->left, hp, k);
        bool right = f(root->right, hp, k);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int , bool> hp;
        return f(root, hp, k);
    }
};