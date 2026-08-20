class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);

        int longest = 0;
        int left = 0;

        for(int right=0; right<s.size(); right++){
            if(last[s[right]] >= left){
                left = last[s[right]]+1;
            }

            last[s[right]] = right;

            longest = max(longest, right-left+1);
        }

        return longest;
    }
};
