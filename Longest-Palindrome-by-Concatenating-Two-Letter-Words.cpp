class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        int ans = 0;
        bool center = false;

        for (auto word : words)
        {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (freq[rev] > 0)
                ans += 4, freq[rev]--;
            else
                freq[word]++;
        }

        for (auto [x, y] : freq)
        {
            if (y > 0 && x[0] == x[1])
            {
                center = true;
                break;
            }
        }

        return ans + (center ? 2 : 0);
    }
};