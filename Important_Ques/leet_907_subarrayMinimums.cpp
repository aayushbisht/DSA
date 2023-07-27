class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int>left(n,0),right(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() and arr[st.top()]>arr[i]) st.pop();
            if(st.size()) left[i] = i-st.top();
            else left[i] = i+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(st.size() and arr[st.top()]>=arr[i]) st.pop();
            if(st.size()) right[i] = st.top()-i;
            else right[i] = n-i;
            st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            long long contri = (left[i]*right[i])%MOD;
            contri = (contri*arr[i])%MOD;
            ans = (ans + contri)%MOD;
        }
        
        return ans%MOD;
    }
};