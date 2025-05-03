class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string result = accumulate(rows.begin(), rows.end(), string());

        return result;
    }
};