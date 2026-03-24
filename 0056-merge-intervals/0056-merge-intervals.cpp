class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> v;
        int n = intervals.size();
        int i=0;

        if(n == 1) {
            return intervals;
        }

        while(i < n) {
            int mini = intervals[i][0];
            int maxi = intervals[i][1];
            while(i < n && maxi >= intervals[i][0]) {
                mini = min(mini, intervals[i][0]);
                maxi = max(maxi, intervals[i][1]);
                i++;
            }
            v.push_back({mini, maxi});

        }
        return v;
    }
};