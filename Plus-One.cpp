class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> result(n + 1, 0);
        int carry = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            int sum = digits[i] + carry;
            result[i + 1] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
        {
            result[0] = carry;
            return result;
        }
        else
            return vector<int>(result.begin() + 1, result.end());
    }
};