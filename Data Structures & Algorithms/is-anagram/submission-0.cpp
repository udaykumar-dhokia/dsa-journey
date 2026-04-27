class Solution {
   public:
    bool isAnagram(string s, string t) {
        if(s.length() == 0 && t.length() == 0){
            return true;
        }

        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> mp;

        for(char c: s){
            mp[c]++;
        }

        for(char c: t){
            mp[c]--;
        }

        for(auto m: mp){
            if(m.second > 0){
                return false;
            }
        }

        return true;
    }
};
