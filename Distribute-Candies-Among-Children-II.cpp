class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        long long result = 0;

        result = (long long)(n + 2) * (n + 1) / 2;

        if (n > limit)
        {
            long long excess1 = n - limit - 1;
            long long excess2 = (n > 2 * limit) ? n - 2 * (limit + 1) : -1;
            long long excess3 = (n > 3 * limit) ? n - 3 * (limit + 1) : -1;

            result -= 3 * (excess1 + 2) * (excess1 + 1) / 2;
            if (excess2 >= 0)
                result += 3 * (excess2 + 2) * (excess2 + 1) / 2;
            if (excess3 >= 0)
                result -= (excess3 + 2) * (excess3 + 1) / 2;
        }

        return result;
    }
};