class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size(), INF = INT_MAX;
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INF)));
        dist[0][0][0] = 0;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> heap;
        heap.emplace(0, 0, 0, 0);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!heap.empty())
        {
            auto [t, x, y, p] = heap.top();
            heap.pop();
            if (t > dist[x][y][p])
                continue;
            if (x == n - 1 && y == m - 1)
                return t;
            int cost = (p == 0) ? 1 : 2;
            int np = p ^ 1;
            for (auto [dx, dy] : dirs)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int nt = max(t, moveTime[nx][ny]) + cost;
                    if (nt < dist[nx][ny][np])
                    {
                        dist[nx][ny][np] = nt;
                        heap.emplace(nt, nx, ny, np);
                    }
                }
            }
        }
        return -1;
    }
};