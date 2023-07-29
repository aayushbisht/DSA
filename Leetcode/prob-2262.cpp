class Solution {
public:
    long long appealSum(string s) {
        vector<int>last(26);
        long long temp = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            if (!last[s[i]-'a'])
                temp += i+1;
            else
                temp += i - last[s[i] - 'a'] + 1;
            last[s[i] - 'a'] = i + 1;
            ans += temp;
        }
        return ans;    
    }
};