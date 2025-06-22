class Solution {
    public:
        vector<string> divideString(string s, int k, char fill) {
            vector<string> result;
            int i = 0;
            while (i < s.length()) {
                string group = "";
                for (int j = 0; j < k; j++) {
                    if (i < s.length()) 
                        group += s[i], i++;
                    else 
                        group += fill;
                }
                result.push_back(group);
            }
            return result;
        }
    };  