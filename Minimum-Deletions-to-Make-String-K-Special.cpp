class Solution {
    public:
        int minimumDeletions(string word, int k) {
            vector<int> freq(26, 0);
            for (char c : word) 
                freq[c - 'a']++;

            vector<int> counts;
            for (int f : freq) {
                if (f > 0) 
                    counts.push_back(f);
            }

            sort(counts.begin(), counts.end());
            int n = counts.size();
            int minDeletions = INT_MAX;

            for (int i = 0; i < n; i++) {
                int deletions = 0;
                int minFreq = counts[i];
                
                for (int j = 0; j < n; j++) {
                    if (counts[j] < minFreq) 
                        deletions += counts[j];
                    else if (counts[j] > minFreq + k) 
                        deletions += counts[j] - (minFreq + k);
                }
                
                minDeletions = min(minDeletions, deletions);
            }

            return minDeletions;
        }
    };