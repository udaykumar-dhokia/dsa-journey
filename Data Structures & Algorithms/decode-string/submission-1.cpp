class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;

        for(int i=0; i<n; i++){
            if(s[i] == ']'){
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();

                int num = 0;
                int base = 1;

                while(!st.empty() && isdigit(st.top())){
                    num += (st.top() - '0') * base;
                    base *= 10;
                    st.pop();
                }
                
                reverse(temp.begin(), temp.end());

                string rep = "";
                for(int i=0; i<num; i++){
                    rep += temp;
                }

                for(char c: rep){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};