class Solution {
public:
    bool check(vector<int> piles, int mid, int h){
        int total_hours = 0;

        for(int pile: piles){
            total_hours += (pile + mid - 1) / mid;

            if(total_hours > h) return false;
        }

        return total_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int pile: piles){
            maxi = max(maxi, pile);
        }

        int left = 1;
        int right = maxi;
        int ans = 0;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(check(piles, mid, h)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};
