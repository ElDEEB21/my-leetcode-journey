class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        int current_area;
        while (l < r)
        {
            current_area = min(height[l], height[r]) * (r - l);
            max_area = max(max_area, current_area);
            height[l] < height[r] ? ++l : --r;
        }

        return max_area;
    }
};