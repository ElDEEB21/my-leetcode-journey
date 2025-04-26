class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long result = 0;
        int n = nums.size();
        int minPos = -1, maxPos = -1, leftBound = -1;

        for (int i = 0; i < n; ++i)
        {
            leftBound = (nums[i] < minK || nums[i] > maxK) ? i : leftBound;
            minPos = (nums[i] == minK) ? i : minPos;
            maxPos = (nums[i] == maxK) ? i : maxPos;
            result += max(0, min(minPos, maxPos) - leftBound);
        }

        return result;
    }
};