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
    //brute approach 
    //do a inorder traversal (will get in sorted order)
    //now again traverse the tree and replace with correct values 
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void traverse(TreeNode* root, vector<int>& v, int& i) {
        if(root == nullptr) {
            return;
        }

        traverse(root->left, v, i);
        if(v[i] != root->val) {
            root->val = v[i];
        }
        i++;
        traverse(root->right, v, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end()); //as now it is not sorted due to swap 
        int i = 0;
        traverse(root, v, i);
    }
};