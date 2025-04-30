class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            int digits = 0;
            while (num > 0)
                num /= 10, digits++;
            count += (digits % 2 == 0);
        }
        return count;
    }
};