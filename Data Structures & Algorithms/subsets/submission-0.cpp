class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(i+1, nums, curr, ans);

        curr.pop_back();
        dfs(i+1, nums, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;

        dfs(0, nums, curr, ans);

        return ans;
    }
};
