class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            if (n == 0) return 0;
            
            vector<int> lastSeen(256, -1);
            int maxLength = 0, start = 0;
            
            for (int i = 0; i < n; i++) 
                start = lastSeen[s[i]] >= start ? lastSeen[s[i]] + 1 : start, lastSeen[s[i]] = i, maxLength = max(maxLength, i - start + 1);
            
            return maxLength;
        }
    };