class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hp;

        for(int i=0;i<nums.size(); i++) {
            if(hp.find(nums[i]) == hp.end()) {
                hp[nums[i]] = i;
            }else {
                if(abs(hp[nums[i]] - i) <= k) {
                    return true;
                }else {
                    hp[nums[i]] = i;
                }
            }
        }
        return false;
    }
};