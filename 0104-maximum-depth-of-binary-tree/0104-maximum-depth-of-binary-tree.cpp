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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int left_side_hgt = maxDepth(root->left);
        int right_side_hgt = maxDepth(root->right);

        if(left_side_hgt > right_side_hgt) {
            return left_side_hgt+1;
        }else {
            return right_side_hgt+1;
        }

    }
};