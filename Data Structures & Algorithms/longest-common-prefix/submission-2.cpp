class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int min_len = INT_MAX;

        for(string s: strs){
            min_len = min(min_len, (int)s.length());
        }

        for(int i=0; i<min_len; i++){
            char c = strs[0][i];

            for(string s: strs){
                if(s[i] != c){
                    return ans;
                }
            }

            ans += c;
        }

        return ans;
    }
};