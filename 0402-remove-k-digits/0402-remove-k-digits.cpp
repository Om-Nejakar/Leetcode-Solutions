class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n = num.length();
        for(int i=0;i<n;i++) {
            while(!st.empty() && k > 0 && (st.top()-'0' > num[i]-'0')) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.empty()) {
            return "0";
        }

        string str;
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }

        while(str.length() != 0 && str.back() == '0') {
            str.pop_back();
        }

        
        reverse(str.begin(), str.end());

        if(str.empty()) {
            return "0";
        }

        return str;
    }
};