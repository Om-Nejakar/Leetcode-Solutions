class Solution {
public:
    const int MOD = 1e9 + 7;
    void findNse(vector<int>& nse, vector<int>& arr, int n) {
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
    }
    void findPse(vector<int>& psee, vector<int>& arr, int n) {
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) { //here we are not poping the equal ele 
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        //next and prev smallest ele but in prev its equal 
        vector<int> nse(n);
        vector<int> psee(n); //equal so tht redundancy does not occur 

        findNse(nse, arr, n);
        findPse(psee, arr, n);

        int total = 0;

        for(int i=0;i<n;i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + (left*right*1LL*arr[i])%MOD)%MOD;
        }
        return total;
    }
};