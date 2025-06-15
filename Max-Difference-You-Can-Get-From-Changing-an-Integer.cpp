class Solution
{
public:
    int maxDiff(int num)
    {
        string s = to_string(num);
        string maxStr = s, minStr = s;

        for (char &c : maxStr)
        {
            if (c != '9')
            {
                char target = c;
                for (char &d : maxStr)
                    if (d == target)
                        d = '9';
                break;
            }
        }

        if (minStr[0] != '1')
        {
            char target = minStr[0];
            for (char &d : minStr)
                if (d == target)
                    d = '1';
        }
        else
        {
            for (int i = 1; i < minStr.length(); i++)
            {
                if (minStr[i] != '0' && minStr[i] != '1')
                {
                    char target = minStr[i];
                    for (char &d : minStr)
                        if (d == target)
                            d = '0';
                    break;
                }
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};