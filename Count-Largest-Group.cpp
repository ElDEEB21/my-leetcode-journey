class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> groupSizes;
        int maxSize = 0, count = 0;

        for (int i = 1; i <= n; ++i)
        {
            int sum = 0, num = i;
            while (num > 0)
                sum += num % 10, num /= 10;
            groupSizes[sum]++;
            maxSize = max(maxSize, groupSizes[sum]);
        }

        for (auto &group : groupSizes)
            count += (group.second == maxSize);

        return count;
    }
};