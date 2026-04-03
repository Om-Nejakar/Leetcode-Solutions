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
    void f(TreeNode* root, vector<string>& v, string s) {
        if(root == nullptr) {
            return;
        }

        s += to_string(root->val) + "->";
        if(root->left == nullptr && root->right == nullptr) {
            v.push_back(s);
        }

        f(root->left, v, s);
        f(root->right, v, s);

        s.pop_back(); // to remove ->
        s.pop_back(); //to removoe the ele 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> v;
        f(root, v, s);
        return v;
    }
};