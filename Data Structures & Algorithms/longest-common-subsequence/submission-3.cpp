class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> dp(m+1, 0), temp(m+1, 0);

        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i == 0 || j == 0) dp[j] = 0;
                else{
                    if(text1[i-1] == text2[j-1]) temp[j] = 1 + dp[j-1];
                    else temp[j] = max(dp[j], temp[j-1]);
                }
            }
            dp = temp;
        }

        return dp[m];
    }
};
