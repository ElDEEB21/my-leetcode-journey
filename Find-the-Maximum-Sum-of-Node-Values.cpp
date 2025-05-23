class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
        function<long long(int, int)> rec = [&](int i, int c) -> long long
        {
            if (i == n)
            {
                if (c == 1)
                    return -(1LL << 31);
                return 0;
            }
            if (dp[i][c] != -1)
                return dp[i][c];

            long long x = nums[i];
            return dp[i][c] = max(x + rec(i + 1, c), (x ^ k) + rec(i + 1, 1 - c));
        };
        return rec(0, 0);
    }
};