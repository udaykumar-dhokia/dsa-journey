class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        dp[0] = 0; dp[1] = 0;

        for(int i=2; i<=cost.size(); i++){
            int one_step = dp[i - 1] + cost[i - 1];
            int two_step = dp[i - 2] + cost[i - 2];
            dp[i] = min(one_step, two_step);
        }

        return dp[cost.size()];
    }
};
