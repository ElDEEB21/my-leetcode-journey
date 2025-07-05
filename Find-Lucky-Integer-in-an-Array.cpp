class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        int result = -1;
        for (auto& pair : freq) {
            if (pair.first == pair.second) 
                result = max(result, pair.first);
        }
        return result;
    }
};