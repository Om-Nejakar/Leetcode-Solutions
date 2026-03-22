class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return 0;
        }

        int maxjump = 0;
        int jump = 0;

        int left = 0;
        int right = 0;

        while(right < n-1) {
            maxjump = 0;
            for(int i=left; i<=right;i++) {
                maxjump = max(i+nums[i], maxjump);
            }
            left = right+1;
            right = maxjump;
            jump++;
            
        }
        return jump;
    }
};