class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        auto check = [&](int x) -> int
        {
            int rotations_top = 0, rotations_bottom = 0;
            for (int i = 0; i < tops.size(); ++i)
            {
                if (tops[i] != x && bottoms[i] != x)
                    return -1;
                if (tops[i] != x)
                    ++rotations_top;
                if (bottoms[i] != x)
                    ++rotations_bottom;
            }
            return min(rotations_top, rotations_bottom);
        };

        int rotations = check(tops[0]);
        if (rotations != -1)
            return rotations;
        return check(bottoms[0]);
    }
};