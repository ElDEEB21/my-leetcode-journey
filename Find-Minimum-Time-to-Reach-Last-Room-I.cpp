class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        minTime[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

        while (!pq.empty())
        {
            auto [currentTime, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if (x == n - 1 && y == m - 1)
                return currentTime;

            if (currentTime > minTime[x][y])
                continue;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int nextTime = max(moveTime[nx][ny], currentTime) + 1;

                    if (nextTime < minTime[nx][ny])
                    {
                        minTime[nx][ny] = nextTime;
                        pq.push({nextTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};