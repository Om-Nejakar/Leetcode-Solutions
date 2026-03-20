class Solution {
public:
    bool f(int i, string s, int n, int opencount, vector<vector<int>>& dp) {
        if(opencount < 0) {
            return false; //if go neg then we came accross ) one extra 
        }
        if(i == n) {
            return opencount == 0; //all valid 
        }

        if(dp[i][opencount] != -1) {
            return dp[i][opencount];
        }

        bool ans = false;
        if(s[i] == '(') {
            ans = f(i+1, s, n, opencount+1, dp);
        }
        if(s[i] == ')') {
            ans = f(i+1, s, n, opencount-1, dp);
        }
        if(s[i] == '*') {
            ans = f(i+1, s, n, opencount+1, dp) || f(i+1, s, n, opencount-1, dp) || f(i+1, s, n, opencount, dp);
        }
        return dp[i][opencount] = ans;
    }
    bool checkValidString(string s) {
        int opencount = 0;
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
        return f(0, s, s.length(), opencount, dp);
    }
};