class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        vector<int> v(3, -1); //now we will store the index 
        int count = 0;

        for(int i=0;i<n;i++) {
            v[s[i]-'a'] = i;

            if(v[0] != -1 && v[1] != -1 && v[2] != -1) { //we got a, b, c
                count += (1 + min({v[0], v[1], v[2]})); //min index+1 is subbaray that are before the req length 
            }
        }
        return count;
    }
};