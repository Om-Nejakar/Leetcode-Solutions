class Solution {
public:
    //2 pointer
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxlen = 0;
        int hp[26] = {0};
        int maxfreq = 0;

        int left = 0;
        int right = 0;

        while(right < n) {
            hp[s[right]-'A']++;
            maxfreq = max(maxfreq, hp[s[right]-'A']);

            if((right-left+1)-maxfreq > k) {
                hp[s[left]-'A']--;
                left++;
            }

            if((right-left+1)-maxfreq <= k) {
                maxlen = max(maxlen, right-left+1);
            }

            right++;
        }

        return maxlen;
    }
};