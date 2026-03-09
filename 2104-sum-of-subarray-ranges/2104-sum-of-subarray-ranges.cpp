class Solution {
public:
    void findNse(int n, vector<int>& nse, vector<int>& nums) {
        stack<int> st;

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void findPse(int n, vector<int>& pse, vector<int>& nums) {
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long sumOfsmallest(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        vector<int> nse(n);
        vector<int> pse(n);

        findNse(n, nse, nums);
        findPse(n, pse, nums);
    
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i] - i;

            total = total +(1LL*left*right*nums[i]);
        }
        return total;
    }
    void findNle(int n, vector<int>& nle, vector<int>& nums) {
        stack<int> st;

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

    }
    void findPle(int n, vector<int>& ple, vector<int>& nums) {
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    long long sumOflargest(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        vector<int> nle(n);
        vector<int> ple(n);

        findNle(n, nle, nums);
        findPle(n, ple, nums);
        for(auto i : nle) {
            cout<<i<<' ';
        }
        for(int i=0;i<n;i++){
            int left = i-ple[i];
            int right = nle[i] - i;

            total = total + (1LL*left*right*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long x = sumOfsmallest(nums);
        long long y = sumOflargest(nums);

        return y-x;
    }
};