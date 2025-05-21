class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m), col(n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                (matrix[i][j] == 0) ? (row[i] = col[j] = true) : (row[i] = row[i], col[j] = col[j]);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n && row[i]; j++)
                matrix[i][j] = 0;

        for (int j = 0; j < n; j++)
            for (int i = 0; i < m && col[j]; i++)
                matrix[i][j] = 0;
    }
};