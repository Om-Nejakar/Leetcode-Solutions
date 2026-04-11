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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left);
        
        if(prev != nullptr && (root->val < prev->val)) { //violation happened
            if(first == nullptr) { //first violation
                first = prev;
                middle = root;
            }else {
                last = root; //second violation
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN); //in inoreder 1st ele is always smallest
        inorder(root);
        
        if(first && last) { //if not adjacent
            swap(first->val, last->val);
        }else if(first && middle) {
            swap(first->val, middle->val);
        }
    }
};