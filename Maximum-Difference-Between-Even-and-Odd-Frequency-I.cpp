class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        int maxOdd = 0, minEven = INT_MAX;
        for (auto &p : freq)
        {
            if (p.second % 2 == 1)
                maxOdd = max(maxOdd, p.second);
            else
                minEven = min(minEven, p.second);
        }

        return maxOdd - minEven;
    }
};