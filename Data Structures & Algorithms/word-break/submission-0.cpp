class Solution {
public:
    bool solve(string &s, unordered_set<string>& st, int idx, vector<int>& dp) {
        if (idx == s.size()) return true;

        if (dp[idx] != -1) return dp[idx];

        for (int len = 1; idx + len <= s.size(); len++) {
            string sub = s.substr(idx, len);
            if (st.count(sub)) {
                if (solve(s, st, idx + len, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(s, st, 0, dp);
    }
};