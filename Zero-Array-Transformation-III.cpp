class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0]; });

        int curSum = 0;
        priority_queue<int> heap;
        vector<int> prefSum(nums.size() + 1, 0);
        int queryIndex = queries.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            while (queryIndex >= 0 && i == queries[queryIndex][0])
                heap.push(queries[queryIndex--][1]);

            curSum += prefSum[i];
            int num = nums[i] - curSum;

            while (!heap.empty() && heap.top() >= i && num-- > 0)
                curSum += 1, prefSum[heap.top() + 1] -= 1, heap.pop();

            if (num > 0)
                return -1;
        }

        return heap.size();
    }
};