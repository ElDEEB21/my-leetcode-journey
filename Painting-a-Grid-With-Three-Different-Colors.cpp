class Solution
{
public:
    int colorTheGrid(int m, int n)
    {
        const int MOD = 1e9 + 7;
        int rows = 0, cols = 0;
        vector<vector<int>> valid_colors;

        auto generate_valid_colors = [&](auto &&self, int curr_pos, int last_color, vector<int> &colors) -> void
        {
            if (curr_pos == rows)
            {
                valid_colors.push_back(colors);
                return;
            }
            for (int color = 0; color < 3; color++)
                if (color != last_color)
                    colors[curr_pos] = color, self(self, curr_pos + 1, color, colors);
        };

        auto is_valid = [&](vector<int> &row1, vector<int> &row2) -> bool
        {
            for (int i = 0; i < rows; i++)
                if (row1[i] == row2[i])
                    return false;
            return true;
        };

        rows = m;
        cols = n;
        valid_colors.clear();

        vector<int> colors(m);
        generate_valid_colors(generate_valid_colors, 0, -1, colors);

        vector<vector<long long>> dp(cols + 1, vector<long long>(valid_colors.size(), 0));

        for (int state = 0; state < valid_colors.size(); state++)
            dp[1][state] = 1;

        for (int col = 1; col < cols; col++)
            for (int prev_state = 0; prev_state < valid_colors.size(); prev_state++)
                for (int curr_state = 0; curr_state < valid_colors.size(); curr_state++)
                    if (is_valid(valid_colors[prev_state], valid_colors[curr_state]))
                        dp[col + 1][curr_state] = (dp[col + 1][curr_state] + dp[col][prev_state]) % MOD;

        long long result = 0;
        for (int state = 0; state < valid_colors.size(); state++)
            result = (result + dp[cols][state]) % MOD;
        return result;
    }
};
