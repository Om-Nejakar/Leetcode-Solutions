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
    int f(TreeNode* root, int& sum) {
        if(root == nullptr) {
            return 0;
        }

        int leftheight = max(0, f(root->left, sum));
        int rightheight = max(0, f(root->right, sum));

        sum = max(sum, leftheight+rightheight+root->val); 
         
        return max(leftheight, rightheight) + root->val;

    }
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        f(root, sum);
        return sum;
    }
};