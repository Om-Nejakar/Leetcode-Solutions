class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hp;
        int ind = 1;
        for(auto& i : nums) {
            hp[i] = ind;
            ind++;
        }

        for(int i=0;i<nums.size();i++) {
            if(hp[target-nums[i]] && (i+1) != hp[target-nums[i]]) {
                return {i, hp[target-nums[i]] - 1};
            }
        }
        return {};
    }
};