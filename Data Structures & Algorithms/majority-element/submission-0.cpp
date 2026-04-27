class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int num = nums[0];
        int freq = 0;

        for(int n: nums){
            if(n == num) freq++;
            else if(n != num) freq--;

            if(freq < 0) num = n;
        }

        return num;
    }
};