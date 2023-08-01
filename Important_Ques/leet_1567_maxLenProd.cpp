class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int preLen = 0, sufLen = 0, preSign = 1, sufSign = 1;
        int ans = INT_MIN , n = nums.size();
        for(int i=0;i<n;i++){
            preLen = nums[i] ? preLen + 1 : 0;
            sufLen = nums[n+~i] ? sufLen + 1 : 0;
            if(nums[i] < 0) preSign = -preSign;
            if(nums[n+~i]<0) sufSign = -sufSign;
            if (nums[i] == 0) preSign = 1;
            if (nums[nums.size()+~i] == 0) sufSign = 1;
            if(preSign == 1 ) ans = max(preLen,ans);
            if(sufSign == 1) ans = max(sufLen,ans);
        }
        return n>1 ? ans : nums[0]>0 ? 1 : 0 ;
    }
};