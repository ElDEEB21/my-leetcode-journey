#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        ordered_set<int> sLeft;
        vector<int> left(n, 0);

        for (int i = 0; i < n; ++i)
            left[i] = sLeft.order_of_key(pos[nums1[i]]), sLeft.insert(pos[nums1[i]]);

        ordered_set<int> sRight;
        vector<int> right(n, 0);

        for (int i = n - 1; i >= 0; --i)
            right[i] = sRight.size() - sRight.order_of_key(pos[nums1[i]]), sRight.insert(pos[nums1[i]]);

        long long result = 0;
        for (int i = 0; i < n; ++i)
            result += (long long)left[i] * right[i];

        return result;
    }
};