class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> curr(n, -1);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[j] = g[i][j];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i > 0) up = g[i][j] + prev[j];
                    if(j > 0) left = g[i][j] + curr[j-1];
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};