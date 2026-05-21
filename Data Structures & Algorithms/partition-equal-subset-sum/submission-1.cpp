class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool> (target+1, false));
        
        for(int i=0; i<nums.size(); i++){
            dp[i][0] = true;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                dp[i][target] = true;
            }
        }

        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<=target; j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take | notTake;
            }
        }

        return dp[nums.size()-1][target];
    }
};
