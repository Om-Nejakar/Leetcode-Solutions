class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size();i++) {

            if(i > j) {
                return false;
            }
            
            j = max(j, i + nums[i]);
        }
        return true;
    }
};