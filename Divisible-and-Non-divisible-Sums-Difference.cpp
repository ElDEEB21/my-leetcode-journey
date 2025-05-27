class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        long long totalSum = (long long)n * (n + 1) / 2;
        long long divisibleCount = n / m;
        long long divisibleSum = m * (divisibleCount * (divisibleCount + 1) / 2);

        return totalSum - 2 * divisibleSum;
    }
};