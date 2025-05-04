class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> count;
        int result = 0;
        for (auto &domino : dominoes)
        {
            int key = (domino[0] < domino[1]) ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0];
            result += count[key]; 
            count[key]++;         
        }
        return result;
    }
};