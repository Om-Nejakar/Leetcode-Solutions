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
    bool leafNode(TreeNode* root) {
        if(!root->left  && !root->right) {
            return true;
        }
        return false;
    }
    bool checkSame(queue<TreeNode*>& Q1, queue<TreeNode*>& Q2) {
        while(!Q1.empty() && !Q2.empty()) {
            TreeNode* q1node = Q1.front(); Q1.pop();
            TreeNode* q2node = Q2.front(); Q2.pop();

            if(!q1node && !q2node) continue;
            if(!q1node || !q2node) {
                return false;
            }
            if(q1node->val != q2node->val) {
                return false;
            }

           
            Q1.push(q1node->left);
            Q2.push(q2node->left);
            Q1.push(q1node->right);
            Q2.push(q2node->right);
            
        }
        return  Q1.empty() && Q2.empty();
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q1, Q2;

        if(!p && q || p && !q) {
            return  false;
        }
        Q1.push(p);
        Q2.push(q);

        return checkSame(Q1, Q2);
    }
};