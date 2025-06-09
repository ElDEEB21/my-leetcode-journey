class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int num = 1;
        for (int i = 1; i < k;)
        {
            int req = check(num, num + 1, n);
            if (i + req <= k)
                i += req, num++;
            else
                i++, num *= 10;
        }
        return num;
    }

private:
    int check(int a, int b, int n)
    {
        int gap = 0;
        long long la = a, lb = b;
        while (la <= n)
            gap += min((long long)n + 1, lb) - la, la *= 10, lb *= 10;
        return gap;
    }
};