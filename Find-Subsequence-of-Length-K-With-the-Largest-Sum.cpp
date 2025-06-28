class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); i++) 
            indexed_nums.push_back({nums[i], i});

        sort(indexed_nums.begin(), indexed_nums.end(), greater<pair<int, int>>());

        vector<int> indices;
        for (int i = 0; i < k; i++) 
            indices.push_back(indexed_nums[i].second);

        sort(indices.begin(), indices.end());

        vector<int> result;
        for (int idx : indices)
            result.push_back(nums[idx]);

        return result;
    }
};