class Solution {
public:
    int num(string& s, int i, vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] - '0' == 0) return 0;

        if(dp[i] != -1) return dp[i];

        int ways = num(s, i+1, dp);

        if(i+1 < s.size()){
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');

            if(n >= 10 && n <= 26){
                ways += num(s, i+2, dp);
            }
        }

        return dp[i] = ways;
    };
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return num(s, 0, dp);
    }
};
