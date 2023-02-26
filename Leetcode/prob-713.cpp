class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, count = 0,l = 0;
        for(int i=0;i<nums.size();i++){
            prod *= nums[i];
            while(prod>=k and l<nums.size()) prod /= nums[l++];
            if(prod<k) count += i-l+1;
        }
        return count;
    }
};