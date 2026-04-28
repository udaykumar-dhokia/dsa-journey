class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int n = word1.length();
        int m = word2.length();

        if(n == 0 && m == 0) return ans;
        if(n == 0) return word2;
        if(m == 0) return word1;

        int left = 0;
        int right = 0;

        while(left < n && right < m){
            ans += word1[left++];
            ans += word2[right++];
        }

        if(left < n){
            for(int i=left; i<n; i++) ans += word1[i];
        }

        if(right < m){
            for(int i=right; i<m; i++) ans += word2[i];
        }

        return ans;
    }
};