class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = g[i][j];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i > 0) up = g[i][j] + dp[i-1][j];
                    if(j > 0) left = g[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};