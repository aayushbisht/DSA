class Solution
{
    public:
        long long zeroFilledSubarray(vector<int> &nums)
        {
            int l = -1;
            long long count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]) l = i;
                else count += i - l;
            }
            return count;
        }
};