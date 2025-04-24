class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        int count = 0;

        unordered_map<int, int> freq;
        int left = 0, distinctCount = 0;

        for (int right = 0; right < n; ++right)
        {
            if (freq[nums[right]] == 0)
                ++distinctCount;
            ++freq[nums[right]];

            while (distinctCount == totalDistinct)
            {
                count += n - right; 
                --freq[nums[left]];
                if (freq[nums[left]] == 0)
                    --distinctCount;
                ++left;
            }
        }

        return count;
    }
};