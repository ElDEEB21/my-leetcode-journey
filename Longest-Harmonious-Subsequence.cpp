class Solution {
    public:
        int findLHS(vector<int>& nums) {
            map<int, int> count;
            for (int num : nums)
                count[num]++;

            int maxLen = 0;
            for (auto& p : count) {
                int num = p.first, freq = p.second;
                if (count.find(num + 1) != count.end()) 
                    maxLen = max(maxLen, freq + count[num + 1]);
            }

            return maxLen;
        }
    };