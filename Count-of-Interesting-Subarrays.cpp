class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int prefixSum = 0;
        long long result = 0;

        for (int num : nums)
        {
            if (num % modulo == k)
                prefixSum++;

            prefixSum %= modulo;

            int target = (prefixSum - k + modulo) % modulo;

            result += prefixCount[target];

            prefixCount[prefixSum]++;
        }

        return result;
    }
};