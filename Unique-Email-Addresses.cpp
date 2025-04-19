class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> uniqueEmails;
        for (auto &email : emails)
        {
            string local, domain;
            bool isDomain = false, ignore = false;
            for (char c : email)
            {
                isDomain = (c == '@') ? true : isDomain;
                ignore = (c == '@') ? false : ignore;
                if (isDomain)
                    domain += c;
                else if (c == '+')
                    ignore = true;
                else if (!ignore && c != '.')
                    local += c;
            }
            uniqueEmails.insert(local + domain);
        }
        return uniqueEmails.size();
    }
};