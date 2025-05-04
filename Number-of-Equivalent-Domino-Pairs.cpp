class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> count;
        int result = 0;
        for (auto &domino : dominoes)
        {
            int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            result += count[key];
            count[key]++;
        }
        return result;
    }
};