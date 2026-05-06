class Solution {
public:
    int tri(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n <= 2) return 1;

        if(dp[n] != -1) return dp[n];

        int one_step = tri(n - 1, dp);
        int two_step = tri(n - 2, dp);
        int three_step = tri(n - 3, dp);

        return dp[n] = one_step + two_step + three_step;
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);

        return tri(n, dp);
    }
};