class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long mx = *max_element(nums.begin(), nums.end());
        long long result = 0, cnt = 0;
        for (int r = 0, l = 0; r < nums.size(); r++)
        {
            if (nums[r] == mx)
                cnt++;
            while (cnt == k)
            {
                result += nums.size() - r;
                if (nums[l] == mx)
                    cnt--;
                l++;
            }
        }

        return result;
    }
};