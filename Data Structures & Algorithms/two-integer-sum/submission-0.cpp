class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        if(nums.size() == 0) return ans;

        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];

            if(mp.find(diff) != mp.end()){
                ans.push_back(min(i, mp[diff]));
                ans.push_back(max(i, mp[diff]));
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
