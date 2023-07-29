class Solution
{
    public:
        using ll = long long;
    int totalStrength(vector<int> &strength)
    {
        int mod = 1e9 + 7;
        int n = strength.size();
        vector<ll> preMin(n, -1), postMin(n, n), preSum(n + 1, 0), kpreSum(n + 2, 0);
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            preSum[i + 1] = (preSum[i] + strength[i]) % mod;
        }
        for (int i = 0; i <= n; ++i)
        {
            kpreSum[i + 1] = (kpreSum[i] + preSum[i]) % mod;
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and strength[st.top()] > strength[i]) st.pop();
            if (!st.empty()) preMin[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and strength[st.top()] >= strength[i]) st.pop();
            if (!st.empty()) postMin[i] = st.top();
            st.push(i);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += ((kpreSum[postMin[i] + 1] - kpreSum[i + 1]) * (i - preMin[i]) % mod + mod - 
               (kpreSum[i + 1] - kpreSum[preMin[i] + 1]) * (postMin[i] - i) % mod) % mod * strength[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};