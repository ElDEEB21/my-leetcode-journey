class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && word[j] == word[i])
                j++;
            int len = j - i;
            if (len > 1) 
                count += len - 1;
            i = j - 1;
        }

        return count;
    }
};