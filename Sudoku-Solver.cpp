class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> rows(9, vector<bool>(9)), cols(9, vector<bool>(9)), boxes(9, vector<bool>(9));

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    int num = board[row][col] - '1';
                    int boxIndex = (row / 3) * 3 + col / 3;
                    rows[row][num] = cols[col][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        function<bool(int, int)> solve = [&](int row, int col) -> bool
        {
            while (row < 9 && board[row][col] != '.')
            {
                col++;
                if (col == 9)
                    col = 0,  row++;
            }
            if (row == 9)
                return true;

            int boxIndex = (row / 3) * 3 + col / 3;
            for (int num = 0; num < 9; num++)
            {
                if (!rows[row][num] && !cols[col][num] && !boxes[boxIndex][num])
                {
                    board[row][col] = '1' + num;
                    rows[row][num] = cols[col][num] = boxes[boxIndex][num] = true;

                    if (solve(row, col))
                        return true;

                    board[row][col] = '.';
                    rows[row][num] = cols[col][num] = boxes[boxIndex][num] = false;
                }
            }
            return false;
        };

        solve(0, 0);
    }
};