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
    void f(TreeNode* root, vector<int>& v) {
        if(root == nullptr) {
            return;
        }

        f(root->left, v);
        v.push_back(root->val);
        f(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        f(root, v);
        vector<int> temp(v.begin(), v.end());
        sort(temp.begin(), temp.end());
        if(temp == v) { //it is bst 
            return true;
        }
        return false; //it is bt
    }
};