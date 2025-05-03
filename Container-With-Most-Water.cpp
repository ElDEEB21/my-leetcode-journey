class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = 0;

        while (l < r)
        {
            int width = r - l;
            int current_area = min(height[l], height[r]) * width;
            max_area = max(max_area, current_area);
            height[l] < height[r] ? ++l : --r;
        }

        return max_area;
    }
};