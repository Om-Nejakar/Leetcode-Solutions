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
    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentnodes) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != nullptr) {
                parentnodes[node->left] = node;
                q.push(node->left);
            }
            if(node->right != nullptr) {
                parentnodes[node->right] = node;
                q.push(node->right);
            }
        }
    }
    TreeNode* findNode(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        TreeNode* left = findNode(root->left, start);
        if (left) return left;
        return findNode(root->right, start);
    }


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentnodes;
        makeParents(root, parentnodes);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        TreeNode* target = findNode(root, start);

        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parentnodes[node] && !visited[parentnodes[node]]) {
                    q.push(parentnodes[node]);
                    visited[parentnodes[node]] = true;
                }
            }
            curr_level++;
        }

        return curr_level-1;      
    }
};