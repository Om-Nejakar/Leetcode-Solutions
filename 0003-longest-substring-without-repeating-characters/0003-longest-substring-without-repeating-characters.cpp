class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hp;

        if(s.length() == 1) {
            return 1;
        }
        int left = 0;
        int right = 0;
        int n = s.length();
        int len = 0;

        while(left <= right && right < n) {
            if(hp.find(s[right]) == hp.end()) {
                hp[s[right]] = 1;
            }else {
                while(hp.find(s[right]) != hp.end()) {
                    hp.erase(s[left]);
                    left++;
                }

                hp[s[right]] = 1;
            }
            len = max(len, right-left+1);
            right++;
        }
        return len;
    }
};