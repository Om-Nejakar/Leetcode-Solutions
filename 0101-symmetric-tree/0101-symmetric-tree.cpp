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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        if(root == nullptr) {
            return true;
        }

        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if(n1 != n2) {
                return false;
            }

            for(int i=0;i<n1;i++) {
                TreeNode* node1 = q1.front();
                TreeNode* node2 = q2.front();
                q1.pop();
                q2.pop();

                if(node1 == nullptr && node2 == nullptr) {
                    continue;
                }
                if(node1==nullptr || node2 == nullptr || node1->val != node2->val) { //if anyone is null 
                    return false;
                }
                
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }
        return true;
    }
};