class Solution
{
    public:
    long long getDescentPeriods(vector<int> &nums)
    {
        long long count = 1;
        int l = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] + 1 != nums[i - 1])
            {
                l = i;
                count++;
            }
            else count += i - l + 1;
        }
        return count;
    }
};