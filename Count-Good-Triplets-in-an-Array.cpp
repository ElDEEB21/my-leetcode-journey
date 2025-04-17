class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = pos[nums1[i]];

        long long result = 0;
        vector<long long> fenwick(n + 1, 0);

        auto update = [&](int idx, int val) {
            for (++idx; idx <= n; idx += idx & -idx)
            fenwick[idx] += val;
        };

        auto query = [&](int idx) {
            long long sum = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
            sum += fenwick[idx];
            return sum;
        };

        vector<long long> left(n, 0), right(n, 0);

        for (int i = 0; i < n; ++i) {
            left[i] = query(v[i] - 1);
            update(v[i], 1);
        }

        fill(fenwick.begin(), fenwick.end(), 0);

        for (int i = n - 1; i >= 0; --i) {
            right[i] = query(n - 1) - query(v[i]);
            update(v[i], 1);
        }

        for (int i = 0; i < n; ++i)
            result += left[i] * right[i];

        return result;
    }
};