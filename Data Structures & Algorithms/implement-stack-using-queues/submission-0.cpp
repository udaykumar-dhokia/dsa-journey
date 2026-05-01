class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }
        else{
            vector<int> temp;
            while(!q2.empty()){
                temp.push_back(q2.front());
                q2.pop();
            }
            reverse(temp.begin(), temp.end());
            for(int num: temp){
                q1.push(num);
            }
            q1.push(x);
        }
    }
    
    int pop() {
        if(!q2.empty()){
            int num = q2.front();
            q2.pop();
            return num;
        }
        else{
            vector<int> temp;
            while(!q1.empty()){
                temp.push_back(q1.front());
                q1.pop();
            }
            reverse(temp.begin(), temp.end());
            for(int num: temp){
                q2.push(num);
            }
            int num = q2.front();
            q2.pop();
            return num;
        }
    }
    
    int top() {
        if(!q2.empty()){
            return q2.front();
        }
        else{
            vector<int> temp;
            while(!q1.empty()){
                temp.push_back(q1.front());
                q1.pop();
            }
            reverse(temp.begin(), temp.end());
            for(int num: temp){
                q2.push(num);
            }
            return q2.front();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */