class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; //sorting acc to end time 
        });

        int n = intervals.size();

        int lastEnd = intervals[0][1];
        int count = 1;

        for(int i=1;i<n;i++) {
            if(intervals[i][0] >= lastEnd) {
                count += 1;
                lastEnd = intervals[i][1];
            }   
        }
        return n-count;
    }
};