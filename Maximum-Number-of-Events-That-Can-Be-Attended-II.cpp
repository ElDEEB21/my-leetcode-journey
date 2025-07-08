class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            int start = events[i-1][0], end = events[i-1][1], value = events[i-1][2];
            
            int lastNonOverlap = 0;
            for (int j = i - 1; j >= 1; j--) {
            if (events[j-1][1] < start) {
                lastNonOverlap = j;
                break;
            }
            }
            
            for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i-1][j], dp[lastNonOverlap][j-1] + value);
            }
        }

        return dp[n][k];
    }
};