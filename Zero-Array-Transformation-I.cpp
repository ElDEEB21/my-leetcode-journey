class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);

        for (const auto &query : queries)
        {
            int start = query[0], end = query[1];
            prefixSum[start]++;
            if (end + 1 <= n)
                prefixSum[end + 1]--;
        }

        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            operations += prefixSum[i];
            if (nums[i] > operations)
                return false;
        }

        return true;
    }
};