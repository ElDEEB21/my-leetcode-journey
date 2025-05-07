class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int count2 = __builtin_popcount(num2), result = num1, count1 = __builtin_popcount(num1);

        if (count1 == count2)
            return num1;

        if (count1 > count2)
        {
            for (int i = 0; i < 32 && count1 > count2; i++)
                if (result & (1 << i))
                    result &= ~(1 << i), count1--;
        }
        else
        {
            for (int i = 0; i < 32 && count1 < count2; i++)
                if (!(result & (1 << i)))
                    result |= (1 << i), count1++;
        }

        return result;
    }
};
