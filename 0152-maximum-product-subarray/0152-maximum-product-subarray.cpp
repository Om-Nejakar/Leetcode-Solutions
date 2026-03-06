class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int minPro = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++) {
            int current = nums[i];
            int temp_max_Pro = max({current, maxPro*current, minPro*current});

            //tracked the neg becs - * - = smallest num gives largetst number when multipled 
            int temp_min_Pro = min({current, maxPro*current, minPro*current});

            maxPro = temp_max_Pro;
            minPro = temp_min_Pro;

            ans = max(ans, maxPro);
        }
        return ans;
    }
};