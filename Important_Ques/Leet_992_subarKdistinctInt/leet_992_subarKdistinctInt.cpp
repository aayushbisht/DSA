class Solution {
public:
    int func(vector<int>& nums, int k) {
    int i = 0, ans = 0;
    unordered_map<int, int> count;
    for (int j = 0; j < nums.size(); ++j) {
        if (!count[nums[j]]++) k--;
        while (k < 0) {
            count[nums[i]]--;
            if (!count[nums[i]]) k++;
            i++;
        }
        ans += j - i + 1;
    }
    return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return func(nums, k) - func(nums, k - 1);
    }
};