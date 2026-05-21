class Solution {
public:
    bool f(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        if(i == 0){
            return nums[0] == target;
        }

        if(dp[i][target] != -1) return dp[i][target];
        
        bool notTake = f(nums, target, i-1, dp);
        bool take = false;
        if(nums[i] <= target){
            take = f(nums, target - nums[i], i-1, dp);
        }
        
        return dp[i][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        return f(nums, target, nums.size()-1, dp);
    }
};
