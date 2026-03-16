class Solution {
public:
    int f(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int noofOdds = 0;
        int count = 0;

        if(k < 0) {
            return 0;
        }
        while(right < nums.size()) {
            if(nums[right]%2 != 0) {
                noofOdds += 1;
            }

            while(noofOdds > k) {
                if(nums[left]%2 != 0) {
                    noofOdds -= 1;
                }
                left++;
            }

            count += (right-left+1);
            right++;
        } 
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};