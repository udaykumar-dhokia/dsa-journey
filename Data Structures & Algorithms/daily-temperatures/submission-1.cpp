class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st;
        int n = t.size();
        if(n == 0) return {};

        vector<int> ans(n,0);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top().first <= t[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i;
            }
            st.push({t[i], i});
        }

        return ans;
    }
};
