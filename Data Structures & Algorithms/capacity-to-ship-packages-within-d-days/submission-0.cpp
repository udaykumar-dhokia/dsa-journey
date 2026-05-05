class Solution {
public:
    bool check(vector<int> weights, int mid, int days){
        int current_days = 1;
        int curr = 0;

        for(int w: weights){
            if(curr + w > mid){
                current_days++;
                curr = 0;
            }
            curr += w;

            if(current_days > days) return false;
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(), weights.end());
        int maxi = accumulate(weights.begin(), weights.end(), 0);

        int ans = 0;

        while(mini <= maxi){
            int mid = mini + (maxi-mini)/2;

            if(check(weights, mid, days)){
                ans = mid;
                maxi = mid - 1;
            }
            else{
                mini = mid + 1;
            }
        }

        return ans;
    }
};