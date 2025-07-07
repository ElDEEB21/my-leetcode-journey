class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        set<int> availableDays;
        int maxDay = 0;
        for (const auto& event : events)
            maxDay = max(maxDay, event[1]);

        for (int i = 1; i <= maxDay; i++) 
            availableDays.insert(i);

        int count = 0;
        for (const auto& event : events) {
            int start = event[0];
            int end = event[1];
            
            auto it = availableDays.lower_bound(start);
            if (it != availableDays.end() && *it <= end) {
                count++;
                availableDays.erase(it);
            }
        }

        return count;
    }
};