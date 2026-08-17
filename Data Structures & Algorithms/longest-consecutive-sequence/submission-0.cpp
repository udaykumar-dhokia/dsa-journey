class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();

        int longest = 0;

        for(int i=0; i<n; i++){
            int current = nums[i];
            int length = 1;

            if(st.find(current-1) == st.end()){
                while(st.find(current+1) != st.end()){
                    current++;
                    length++;
                }
            }

            longest = max(longest, length);
        }

        return longest;
    }
};
