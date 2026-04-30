class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        if(n == 0) return 0;

        stack<int> st;

        for(int i=0; i<n; i++){
            if(operations[i] == "+"){
                int prev_1 = st.top();
                st.pop();
                int prev_2 = st.top();
                st.push(prev_1);
                st.push(prev_1 + prev_2);
            }
            else if(operations[i] == "D"){
                int prev = st.top();
                st.push(2*prev);
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else{
                st.push(stoi(operations[i]));
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};