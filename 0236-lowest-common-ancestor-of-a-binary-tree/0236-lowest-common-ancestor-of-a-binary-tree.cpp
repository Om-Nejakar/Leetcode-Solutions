/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, TreeNode* p, vector<TreeNode*>& v) {
        if(root == nullptr) {
            return false;
        }

        v.push_back(root);

        if(root == p) {
            return true;
        }

        if(f(root->left, p, v) || f(root->right, p, v)) {
            return true;
        }
        v.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        vector<TreeNode*> v3;
        f(root, p, v1);
        f(root, q, v2);

        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
        return v3.back();
    }
};