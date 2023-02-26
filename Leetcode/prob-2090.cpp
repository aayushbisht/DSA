class Solution {
public:
    using ll = long long;
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>pref;
        ll p = 0;
        for(auto x : nums){
            p+=x;
            pref.push_back(p);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i-k<0 or i+k>=n) ans.push_back(-1);
            else{
                ll sum = pref[i+k] - pref[i-k] + nums[i-k];
                ll t =  sum/((k*2)+1);
                ans.push_back(t);
            }
        }
        return ans;
    }
};