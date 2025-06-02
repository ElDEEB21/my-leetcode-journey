class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
            candies[i] = ratings[i] > ratings[i-1] ? candies[i-1] + 1 : 1;

        for (int i = n-2; i >= 0; i--)
            candies[i] = ratings[i] > ratings[i+1] ? max(candies[i], candies[i+1] + 1) : candies[i];

        return accumulate(candies.begin(), candies.end(), 0);
    }
};