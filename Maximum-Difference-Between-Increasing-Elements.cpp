class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int maxDiff = -1, minElement = nums[0];

        for (int i = 1; i < nums.size(); i++)
            nums[i] > minElement ? maxDiff = max(maxDiff, nums[i] - minElement) : minElement = nums[i];

        return maxDiff;
    }
};