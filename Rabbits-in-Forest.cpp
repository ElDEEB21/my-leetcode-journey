class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        vector<int> count(1000, 0);
        for (int answer : answers)
            count[answer]++;

        int rabbits = 0;
        for (int i = 0; i < 1000; ++i)
        {
            if (count[i] > 0)
            {
                int groupSize = i + 1;
                int groups = (count[i] + groupSize - 1) / groupSize;
                rabbits += groups * groupSize;
            }
        }

        return rabbits;
    }
};