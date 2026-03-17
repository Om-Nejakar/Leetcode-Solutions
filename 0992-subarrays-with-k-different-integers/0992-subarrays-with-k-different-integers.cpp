class Solution {
public:
    int f(vector<int>& nums, int k) {
        map<int, int> mp;
        int left = 0;
        int count = 0;
        if(k < 0) {
            return 0;
        }
        for(int right=0;right<nums.size();right++) {
            mp[nums[right]]++;
            while(mp.size() > k) {
                mp[nums[left]]--;

                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += (right-left+1);
            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k)-f(nums, k-1);
    }    
};