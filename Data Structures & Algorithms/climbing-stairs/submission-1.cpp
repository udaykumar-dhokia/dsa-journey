class Solution {
public:
    int climb(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(n == 1) return 1;

        int left = dp[n-1] != -1 ? dp[n-1] : dp[n-1] = climb(n-1, dp);
        int right = dp[n-2] != -1 ? dp[n-2] : dp[n-2] = climb(n-2, dp);

        return dp[n] = left + right;
    }
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        
        vector<int> dp(n+1, -1);
        climb(n, dp);

        return dp[n];
    }
};
