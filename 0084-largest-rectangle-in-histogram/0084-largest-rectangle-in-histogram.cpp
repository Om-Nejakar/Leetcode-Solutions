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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);

        findNse(n, nse, heights);
        findPse(n, pse, heights);

        int area = 0;
        for(int i=0;i<n;i++) {
            int hgt = heights[i];
            int width = (nse[i] - i) + (i - pse[i] - 1) ; //-1 becs not to include curr ele 2 times 

            area = max(area, hgt*width);
        }
        return area;
    }
};