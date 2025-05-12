class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        set<int> resultSet;
        int n = digits.size();
        vector<int> count(10, 0);

        for (int digit : digits)
            count[digit]++;

        for (int i = 1; i < 10; i++)
        {
            if (count[i] == 0)
                continue;
            count[i]--;

            for (int j = 0; j < 10; j++)
            {
                if (count[j] == 0)
                    continue;
                count[j]--;

                for (int k = 0; k < 10; k += 2)
                {
                    if (count[k] == 0)
                        continue;
                    resultSet.insert(i * 100 + j * 10 + k);
                }
                count[j]++;
            }
            count[i]++;
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};