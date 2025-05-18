class Solution
{
public:
    int colorTheGrid(int m, int n)
    {
        const int MOD = 1e9 + 7;
        vector<int> validStates;
        vector<vector<int>> transitions;

        int maxState = pow(3, m);
        for (int state = 0; state < maxState; state++)
        {
            int curr = state;
            bool valid = true;
            int last = -1;

            for (int i = 0; i < m; i++)
            {
                int color = curr % 3;
                if (color == last)
                {
                    valid = false;
                    break;
                }
                last = color;
                curr /= 3;
            }

            if (valid)
                validStates.push_back(state);
        }

        int stateCount = validStates.size();
        transitions.resize(stateCount);

        for (int i = 0; i < stateCount; i++)
        {
            for (int j = 0; j < stateCount; j++)
            {
                int state1 = validStates[i];
                int state2 = validStates[j];
                bool valid = true;

                for (int k = 0; k < m; k++)
                {
                    if ((state1 % 3) == (state2 % 3))
                    {
                        valid = false;
                        break;
                    }
                    state1 /= 3;
                    state2 /= 3;
                }

                if (valid)
                    transitions[i].push_back(j);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(stateCount, 0));
        for (int i = 0; i < stateCount; i++)
            dp[0][i] = 1;

        for (int col = 1; col < n; col++)
        {
            for (int curr = 0; curr < stateCount; curr++)
            {
                for (int prev : transitions[curr])
                {
                    dp[col][curr] = (dp[col][curr] + dp[col - 1][prev]) % MOD;
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < stateCount; i++)
        {
            result = (result + dp[n - 1][i]) % MOD;
        }
        return result;
    }
};
