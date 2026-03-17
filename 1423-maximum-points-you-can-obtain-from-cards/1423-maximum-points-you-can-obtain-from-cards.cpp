class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;

        for(int i=0;i<k;i++) {
            sum += cardPoints[i];
        }

        int maxsum = sum; //for the initial state 

        int z = n-1;
        for(int i=k-1;i>=0;i--) {
            sum = sum-cardPoints[i]+cardPoints[z--];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};