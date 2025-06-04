class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;

        int n = word.length();
        int maxLen = n - (numFriends - 1);
        string result = "";

        char maxChar = *max_element(word.begin(), word.end());

        for (int i = 0; i < n; i++)
        {
            if (word[i] == maxChar)
            {
                int actualMaxLen = min(maxLen, n - i);
                string candidate = word.substr(i, actualMaxLen);
                if (candidate > result)
                    result = candidate;
            }
        }

        return result;
    }
};
