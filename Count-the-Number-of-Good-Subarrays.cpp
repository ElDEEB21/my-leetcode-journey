class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int left = 0, right = 0, n = nums.size();
        long long count = 0, pairs = 0;

        while (right < n)
        {
            pairs += freq[nums[right]],freq[nums[right]]++, right++;

            while (pairs >= k)
                count += n - right + 1, freq[nums[left]]--, pairs -= freq[nums[left++]];
        }

        return count;
    }
};