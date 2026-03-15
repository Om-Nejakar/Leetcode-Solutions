class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int len = 0;

        while(left <= right && right < n) {
            if(nums[right] == 1) {
                right++;
            }else {
                if(k > 0) {
                    k -= 1;
                    right++;
                }
                else if(k == 0) {
                    if(right == left) {
                        right++;
                        left++;
                    }else {
                        while(nums[left] != 0) {
                            left++;
                        }
                        if(left != right) {
                            left++;
                            k += 1;
                        }
                    }
                    
                }
            }
            len = max(len, right-left);
        }   
        return len;
    }
};