class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long minVal = 0, maxVal = 0, current = 0;
        for (int diff : differences)
            current += diff, minVal = min(minVal, current), maxVal = max(maxVal, current);
        long long range = (upper - lower) - (maxVal - minVal) + 1;
        return range > 0 ? range : 0;
    }
};