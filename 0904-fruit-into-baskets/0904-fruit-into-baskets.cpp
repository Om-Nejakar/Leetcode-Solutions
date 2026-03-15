class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 0) return 0;
        else if(n == 1) return 1;
        unordered_map<int, int> hashmap;
        int left = 0, len = 0;

        for(int right=0;right<n;right++) {
            hashmap[fruits[right]] += 1;

            while(hashmap.size() > 2) {
                hashmap[fruits[left]] -= 1;
                if(hashmap[fruits[left]] == 0) {
                    hashmap.erase(fruits[left]);
                }
                left++;
            }
            len = max(len, right-left+1);
        }
        return len;
    }
};