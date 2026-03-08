class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i=0;i<n;i++) {
            while(!st.empty() && (asteroids[i] < 0 && st.top() > 0) && (abs(asteroids[i]) > st.top())) {
                st.pop();
            }

            if(!st.empty() && st.top() > 0 && asteroids[i] < 0 && abs(asteroids[i]) == st.top()) {
                st.pop();
                continue;
            } 
            if(!st.empty() && asteroids[i] < 0 && (abs(asteroids[i]) < st.top())) {
                continue;
            }
            st.push(asteroids[i]);
        }

        vector<int> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());
        return v;
    }
};