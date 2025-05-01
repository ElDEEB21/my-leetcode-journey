class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto canComplete = [&](int taskCount) -> bool
        {
            multiset<int> availableWorkers(workers.end() - taskCount, workers.end());
            int remainingPills = pills;

            for (int i = taskCount - 1; i >= 0; --i)
            {
                auto it = availableWorkers.lower_bound(tasks[i]);
                if (it != availableWorkers.end())
                    availableWorkers.erase(it);
                else if (remainingPills > 0)
                {
                    it = availableWorkers.lower_bound(tasks[i] - strength);
                    if (it == availableWorkers.end())
                        return false;
                    availableWorkers.erase(it);
                    --remainingPills;
                }
                else return false;
            }
            return true;
        };

        int l = 0, r = min(tasks.size(), workers.size()), ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (canComplete(mid))
                ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        return ans;
    }
};