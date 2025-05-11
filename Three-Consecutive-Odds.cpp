class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            (arr[i] & 1) ? count++ : count = 0;
            if (count == 3)
                return true;
        }
        return false;
    }
};