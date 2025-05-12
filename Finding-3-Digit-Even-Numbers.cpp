class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> ans;
        sort(digits.begin(), digits.end());
        int n = digits.size();
        for (int i = 0; i < n; i++)
        {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (i == k || j == k)
                        continue;
                    if (digits[k] % 2 == 0)
                        ans.push_back(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};