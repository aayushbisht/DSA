class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long reach = 0;
        int ans = 0,i=0;
        while(reach<n){
            if(i<nums.size() and nums[i]<=reach+1){
                reach += nums[i];
                i++;
            }
            else{
                reach += reach +1;
                ans++;
            }
        }
        return ans;
    }
};