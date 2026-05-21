class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<bool> dp(target+1, false);
        
        dp[0] = true;

        for(int i=0; i<nums.size(); i++){
            vector<bool> temp(target+1, false);
            temp[0] = true;
            for(int j=0; j<=target; j++){
                bool notTake = dp[j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[j-nums[i]];
                }
                temp[j] = take | notTake;
            }
            dp = temp;
        }

        return dp[target];
    }
};
