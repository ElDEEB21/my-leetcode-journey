class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0, sum2 = 0;
        int countZeros1 = 0, countZeros2 = 0;

        for (int num : nums1)
            num == 0 ? countZeros1++ : sum1 += num;

        for (int num : nums2)
            num == 0 ? countZeros2++ : sum2 += num;

        long long min1 = sum1 + countZeros1;
        long long min2 = sum2 + countZeros2;

        if (countZeros1 == 0 && countZeros2 == 0)
            return sum1 == sum2 ? sum1 : -1;
        else if (countZeros1 == 0)
            return sum2 + countZeros2 <= sum1 ? sum1 : -1;
        else if (countZeros2 == 0)
            return sum1 + countZeros1 <= sum2 ? sum2 : -1;
        return max(min1, min2);
    }
};