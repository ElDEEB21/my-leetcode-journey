class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        int i = 0;
        while (i < s.length() - 1 && s[i] == '9')
            i++;

        string mx = s;
        for (char &c : mx)
            c == s[i] ? c = '9' : c;

        string mn = s;
        for (char &c : mn)
            c == s[0] ? c = '0' : c;

        return stoi(mx) - stoi(mn);
    }
};