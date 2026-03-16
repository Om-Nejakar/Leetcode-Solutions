class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hashmap;
        int window_size = 0, left = 0, max_count = 0, len = 0;

        for(int right=0;right<s.length();right++) {
            hashmap[s[right]] += 1; // store the count in the map
            max_count = max(max_count, hashmap[s[right]]); // take the highest freq count 

            window_size = right - left + 1;
            if((window_size - max_count) > k) { // its like win = frq + k (>k it means that it has more variable hence reduce the size fromm left )
                hashmap[s[left]] -= 1;
                left++;
            }

            len = max(len, right-left+1); // make the length comparision 
        }
        return len;
    }
};