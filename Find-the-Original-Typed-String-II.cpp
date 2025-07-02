class Solution {
    public:
        int possibleStringCount(string word, int k) {
            const int MOD = 1e9 + 7;
            vector<int> groups;
            int n = word.length();

            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && word[j] == word[i]) j++;
                groups.push_back(j - i);
                i = j;
            }

            int m = groups.size();
            if (k > n) return 0;
            
            long long total = 1;
            for (int g : groups) {
                total = (total * g) % MOD;
            }
            
            if (k <= m) return total;

            vector<int> dp(k, 0);
            dp[0] = 1;

            for (int num : groups) {
                vector<int> newDp(k, 0);
                long long sum = 0;
                for (int s = 0; s < k; ++s) {
                    if (s > 0) sum = (sum + dp[s - 1]) % MOD;
                    if (s > num) sum = (sum - dp[s - num - 1] + MOD) % MOD;
                    newDp[s] = sum;
                }
                dp = newDp;
            }

            long long invalid = 0;
            for (int s = m; s < k; ++s) {
                invalid = (invalid + dp[s]) % MOD;
            }

            return (total - invalid + MOD) % MOD;
        }
    };