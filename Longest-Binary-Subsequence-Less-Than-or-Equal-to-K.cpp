class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int zeros = 0, ones = 0;

        for (char c : s) 
            zeros += (c == '0');

        long long value = 0;
        long long power = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (value + power <= k) {
                    value += power;
                    ones++;
                }
            }
            power *= 2;
            if (power > k) break; 
        }

        return zeros + ones;
    }
};