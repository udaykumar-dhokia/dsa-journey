class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;

        vector<int> ans;
        
        while(left < m && right < n){
            if(nums1[left] < nums2[right]){
                ans.push_back(nums1[left++]);
            } else{
                ans.push_back(nums2[right++]);
            }
        }

        if(left < m){
            for(int i = left; i<m; i++) ans.push_back(nums1[i]);
        }
        if(right < n){
            for(int i = right; i<n; i++) ans.push_back(nums2[i]);
        }

        for(int i=0; i<m+n; i++){
            nums1[i] = ans[i];
        }
    }
};