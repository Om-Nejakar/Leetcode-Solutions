class Solution {
public:
    int f(vector<int>& nums, int goal) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;

        if(goal < 0) {
            return 0;
        }
        
        while(right < n) {
            sum += nums[right];

            while(sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += (right-left+1); //adding the len means that many subbarray <= goal 
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return f(nums, goal) - f(nums, goal-1);
    }
};