class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (abs(target - currentSum) < abs(target - result))
                    result = currentSum;
                if (currentSum < target)
                    ++left;
                else if (currentSum > target)
                    --right;
                else
                    return currentSum;
            }
        }
        return result;
    }
};