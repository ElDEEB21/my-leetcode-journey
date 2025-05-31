class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int target = n * n;

        auto getCoords = [&](int pos) -> pair<int, int>
        {
            int row = n - 1 - (pos - 1) / n;
            int col = (pos - 1) % n;
            if ((n - 1 - row) % 2 == 1)
                col = n - 1 - col;
            return {row, col};
        };

        queue<pair<int, int>> q; // {position, moves}
        vector<bool> visited(target + 1, false);
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty())
        {
            auto [pos, moves] = q.front();
            q.pop();

            if (pos == target)
                return moves;

            for (int dice = 1; dice <= 6; dice++)
            {
                int next = pos + dice;
                if (next > target)
                    break;

                auto [row, col] = getCoords(next);
                if (board[row][col] != -1)
                    next = board[row][col];

                if (!visited[next])
                    visited[next] = true, q.push({next, moves + 1});
            }
        }

        return -1;
    }
};