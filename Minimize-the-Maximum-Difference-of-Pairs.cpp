class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums[0];

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (canFormPairs(nums, p, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    bool canFormPairs(vector<int> &nums, int p, int maxDiff)
    {
        int pairs = 0;
        int i = 0;

        while (i < nums.size() - 1 && pairs < p)
        {
            if (nums[i + 1] - nums[i] <= maxDiff)
                pairs++, i += 2; 
            else
                i++;
        }

        return pairs >= p;
    }
};