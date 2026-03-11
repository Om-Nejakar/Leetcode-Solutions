class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;
    StockSpanner() {
        index = -1;
        // st.clear();
    }
    
    int next(int price) {
        index += 1;

        //its basically next greater ele 
        while(!st.empty() && price >= st.top().second) {
            st.pop();
        }

        //i-nge so we get the consecutive days
        int ans = index - (st.empty() ? -1 : st.top().first);
        st.push({index, price});
        return ans; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */