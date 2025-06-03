class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        queue<int> q;
        unordered_set<int> hasBox, hasKey;
        int totalCandies = 0;

        for (int box : initialBoxes)
        {
            hasBox.insert(box);
            if (status[box] == 1)
                q.push(box);
        }

        while (!q.empty())
        {
            int currentBox = q.front();
            q.pop();

            totalCandies += candies[currentBox];

            for (int key : keys[currentBox])
            {
                hasKey.insert(key);
                if (hasBox.count(key) && status[key] == 0)
                    q.push(key),status[key] = 1;
            }

            for (int newBox : containedBoxes[currentBox])
            {
                if (!hasBox.count(newBox))
                {
                    hasBox.insert(newBox);
                    if (status[newBox] == 1 || hasKey.count(newBox))
                    {
                        q.push(newBox);
                        if (status[newBox] == 0)
                            status[newBox] = 1;
                    }
                }
            }
        }

        return totalCandies;
    }
};