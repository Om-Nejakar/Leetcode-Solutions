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
    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentnodes, TreeNode* target) {
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentnodes;
        makeParents(root, parentnodes, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!q.empty()) {
            int size = q.size();
            if(curr_level == k) {
                break;
            }
            curr_level++;

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
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            res.push_back(node->val);
        }
        return res;
    }
};