class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string t;
        char del = '/';
        stack<string> st;

        while(getline(ss,t,del)){
            if(t == ".."){
                if(!st.empty()) st.pop();
                else continue;
            }
            else if(t == "" || t == "."){
                continue;
            }
            else{
                st.push(t);
            }
        }

        if(st.empty()) return "/";

        vector<string> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans = "";

        for(string s: temp){
            ans = ans + "/" + s;
        }

        return ans;
    }
};