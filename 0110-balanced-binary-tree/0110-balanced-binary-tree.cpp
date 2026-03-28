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

    int f(TreeNode* root, int& ans) {
        if(root == nullptr) {
            return 0;
        }

        int x = f(root->left, ans);
        int y = f(root->right, ans);

        if(abs(x-y) > 1) {
            ans = 1;
        }

        if(x > y) {
            return x+1;
        }else {
            return y+1;
        }

    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        int ans = 0;

        f(root, ans);
        if(ans == 1) {
            return false;
        }

        return true;
    }
    
};