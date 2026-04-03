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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        long long distance = 0;

        if(root == nullptr) {
            return 0;
        }

        q.push({root, 0}); // root index is 0

        while(!q.empty()) {
            int size = q.size();
            long long minIndexVal = q.front().second;
            long long first, last;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                long long firstNodeIndx = q.front().second;
                q.pop();

                long long childIndex = firstNodeIndx - minIndexVal;
                if(i == 0) {
                    first = childIndex;
                }
                if(i == size-1) {
                    last = childIndex;
                }
                if(node->left != nullptr) {
                    q.push({node->left, childIndex*2 + 1});
                }
                if(node->right != nullptr) {
                    q.push({node->right, childIndex*2 + 2});
                }
            }
            distance = max(distance, (int)last-first+1);
        }
        return distance;
    }
};