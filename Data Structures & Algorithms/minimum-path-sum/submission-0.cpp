class Solution {
public:
    int f(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return g[i][j];
        if(i < 0 || j < 0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, g, dp);
        int left = f(i, j-1, g, dp);

        int ans = INT_MAX;

        if(up != INT_MAX){
            ans = min(ans, g[i][j]+up);
        }

        if(left != INT_MAX){
            ans = min(ans, g[i][j]+left);
        }

        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m-1, n-1, g, dp);
    }
};