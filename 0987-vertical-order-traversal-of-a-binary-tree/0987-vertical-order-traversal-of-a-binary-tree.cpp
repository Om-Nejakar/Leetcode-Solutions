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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> mp;

        if(root == nullptr) {
            return ans;
        }

        q.push({root, {0,0}});

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                int level = q.front().second.first;
                int vet_level = q.front().second.second;
                q.pop();

                mp[vet_level].push_back({level, node->val});

                if(node->left != nullptr) {
                    q.push({node->left, {level+1, vet_level-1}});
                }
                if(node->right != nullptr) {
                    q.push({node->right, {level+1, vet_level+1}});
                }
            }
        }

        for(auto& p : mp) {
            auto& vec = p.second;
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                if(a.first == b.first) {
                    return a.second < b.second;
                }else {
                    return a.first < b.first;
                }
            });

            vector<int> v;
            for(auto& p : vec) {
                v.push_back(p.second);
            }
            ans.push_back(v);

        }
        return ans;
    
    }
};