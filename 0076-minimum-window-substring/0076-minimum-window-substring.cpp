class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hp;
        int startIndex = -1;
        int minLen = INT_MAX;
        int left = 0;
        int count = 0;

        for(auto& c : t) { //we have pre inserted the char values 
            hp[c]++;
        }

        for(int right=0;right<s.length();right++) {
            if(hp[s[right]] > 0) { //we have precomputed char so including it will give that min req char from t 
                count += 1;    
            }
            hp[s[right]]--; //it means taken if ele was not there it becomes more neg 

            while(count == t.length()) { //so that we can decrease the len to check how much small we can make 
                if(right-left+1 < minLen) {
                    minLen = right-left+1;
                    startIndex = left;
                }

                hp[s[left]]++;
                if(hp[s[left]] > 0) {
                    count -= 1;
                }
                left++;
            }
        } 
        return startIndex==-1 ? "": s.substr(startIndex, minLen);  
    }
};