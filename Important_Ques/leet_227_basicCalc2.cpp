class Solution {
public:
    int calculate(string s) {
        s += '+';
        long long cur = 0, ans = 0;
        char prevSign = '+';
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])) cur = cur*10 + (s[i]-'0');
            else if(s[i] != ' '){
                if(prevSign == '+' ) st.push(cur);
                else if(prevSign == '-') st.push(cur*(-1));
                else if(prevSign == '*'){
                    int x = st.top();
                    st.pop();
                    st.push(cur*x);
                }
                else if(prevSign == '/'){
                    int x = st.top();
                    st.pop();
                    st.push(x/cur);
                }
                prevSign = s[i];
                cur = 0;
                
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};