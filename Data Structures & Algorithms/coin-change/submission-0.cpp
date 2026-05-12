class Solution {
public:
    int f(vector<int>& coins, int i, int t, vector<vector<int>>& dp){
        if(i == 0){
            if(t % coins[0] == 0){
                return t / coins[0];
            }
            return 1e9;
        }

        if(dp[i][t] != -1) return dp[i][t];

        int notTake = f(coins, i-1, t, dp);
        
        int take = 1e9;
        if(coins[i] <= t){
            take = 1 + f(coins, i, t - coins[i], dp);
        }

        return dp[i][t] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = f(coins, coins.size() - 1, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
