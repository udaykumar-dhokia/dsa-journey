class Solution {
public:
    int minCost(vector<int>& cost, int start, vector<int>& dp){
        if(start <= 1) return 0;
        
        if(dp[start] != -1) return dp[start];

        int one_step = minCost(cost, start-1, dp) + cost[start-1];
        int two_step = INT_MAX;

        if(start > 1) two_step = minCost(cost, start-2, dp) + cost[start-2];

        return dp[start] = min(one_step, two_step);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return minCost(cost, cost.size(), dp);
    }
};
