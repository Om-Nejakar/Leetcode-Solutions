class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = 0;
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        if(n == 1) {
            return 1;
        }

        for(int i=0;i<n;i++) {
            if(i != 0) {
                if(ratings[i] > ratings[i-1]) {
                    left[i] += left[i-1];
                }else {
                    continue;
                }
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(i != n-1) {
                if(ratings[i] > ratings[i+1]) {
                    right[i] += right[i+1];
                }else {
                    continue;
                }
            }
        }

        for(int i=0;i<n;i++) {
            candies += max(left[i], right[i]);
        }
        return candies;
    }
};