class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[i] = i / coins[0];
            }
            else{
                dp[i] = 1e9;
            }
        }

        for(int i=1; i<coins.size(); i++){
            vector<int> temp(amount+1, -1);
            for(int t=0; t<=amount; t++){
                int notTake = dp[t];
                int take = 1e9;
                if(coins[i] <= t){
                    take = 1 + temp[t - coins[i]];
                }

                temp[t] = min(take, notTake);
            }
            dp = temp;
        }

        int ans = dp[amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};
