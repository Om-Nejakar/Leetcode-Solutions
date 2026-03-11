class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++) {
            //maintaining the size = k 
            if(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            //if larger ele comes we have to pop so that large is at front and dec mono stack
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);

            //first time we have to put 3 ele 
            if(i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }   
        return ans;
    }
};