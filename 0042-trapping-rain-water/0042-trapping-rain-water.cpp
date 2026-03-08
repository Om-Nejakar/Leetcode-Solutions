class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //for stroing the global height both side 
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int leftMax = 0, rightMax = 0;

        for(int i=0;i<n;i++) {
            left[i] = max(leftMax, height[i]);
            leftMax = max(leftMax, height[i]);
        }
        for(int i=n-1; i>=0; i--) {
            right[i] = max(rightMax, height[i]);
            rightMax = max(rightMax, height[i]);
        }

        int waterCapacity = 0;
        
        for(int i=0;i<n;i++) {
            int hgt = min(left[i], right[i]);
            int waterStore = abs(height[i]-hgt);
            waterCapacity += waterStore;
        }
        return waterCapacity;
    }
};