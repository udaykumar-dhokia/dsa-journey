class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        if(nums.size() == 1){
            return nums[0] == val ? 0 : 1;
        }

        int left = 0;
        int right = nums.size()-1;
        while(nums[right] == val){
            right--;
        }

        while(left <= right){
            if(nums[left] == val){
                swap(nums[left], nums[right]);
            }
            left++;
            while(nums[right] == val){
                right--;
            }
        }

        return left;
    }
};