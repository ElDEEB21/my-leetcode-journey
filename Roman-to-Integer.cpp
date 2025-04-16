class Solution
{
public:
    int romanToInt(string s)
    {
        int romanMap[26] = {0};
        romanMap['I' - 'A'] = 1;
        romanMap['V' - 'A'] = 5;
        romanMap['X' - 'A'] = 10;
        romanMap['L' - 'A'] = 50;
        romanMap['C' - 'A'] = 100;
        romanMap['D' - 'A'] = 500;
        romanMap['M' - 'A'] = 1000;

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (i < n - 1 && romanMap[s[i] - 'A'] < romanMap[s[i + 1] - 'A'])
                result -= romanMap[s[i] - 'A'];
            else
                result += romanMap[s[i] - 'A'];
        }

        return result;
    }
};