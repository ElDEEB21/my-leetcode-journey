class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        vector<vector<int>> prev(n, vector<int>(2, -1));

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (groups[i] != groups[j] && dp[j][groups[j]] + 1 > dp[i][groups[i]])
                    dp[i][groups[i]] = dp[j][groups[j]] + 1, prev[i][groups[i]] = j;

        int maxLen = 1, endIdx = 0;
        for (int i = 0; i < n; i++)
            if (dp[i][groups[i]] > maxLen)
                maxLen = dp[i][groups[i]], endIdx = i;

        vector<string> result;
        while (endIdx != -1)
            result.push_back(words[endIdx]), endIdx = prev[endIdx][groups[endIdx]];
        reverse(result.begin(), result.end());
        return result;
    }
};