class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        string ans = "";

        for(string s: strs){
            min_len = min(min_len, (int) s.length());
        }

        for(int i=0; i<min_len; i++){
            char c = strs[0][i];
            bool flag = true;

            for(string s: strs){
                if(s[i] != c){
                    if(i == 0){
                        return ans;
                    }
                    flag = false;
                }
            }

            if(flag) ans += c;
        }

        return ans;
    }
};