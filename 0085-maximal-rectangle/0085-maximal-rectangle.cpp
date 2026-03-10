class Solution {
public:
    void NSL(vector<int>& v, vector<int>& left) {
        stack<int> st;
        int n = v.size();
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(i);
                left.push_back(-1);
            }else {
                while(!st.empty() && v[i] <= v[st.top()]) {
                    st.pop();
                }

                if(!st.empty() && v[i] > v[st.top()]) {
                    left.push_back(st.top());
                    st.push(i);
                }else {
                    st.push(i);
                    left.push_back(-1);
                }
            }
        }
    }
    void NSR(vector<int>& v, vector<int>& right) {
        stack<int> st;
        int n = v.size();
        for(int i=n-1;i>=0;i--) {
            if(st.empty()) {
                st.push(i);
                right.push_back(n);
            }else {
                while(!st.empty() && v[i] <= v[st.top()]) {
                    st.pop();
                }

                if(!st.empty() && v[i] > v[st.top()]) {
                    right.push_back(st.top());
                    st.push(i);
                }else {
                    st.push(i);
                    right.push_back(n);
                }
            }
        }
        reverse(right.begin(), right.end());
    }
    int MAH(vector<int> v) {
        vector<int> right;
        vector<int> left;

        NSL(v, left);
        NSR(v, right);

        int area = 0;
        for(int i=0;i<v.size();i++) {
            area = max(area, (right[i]-left[i]-1)*v[i]);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m, 0);
        int area = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '0') {
                    v[j] = 0;
                }else {
                    v[j] += 1;
                }
            }

            area = max(area, MAH(v));
        }

        return area;
    }
};