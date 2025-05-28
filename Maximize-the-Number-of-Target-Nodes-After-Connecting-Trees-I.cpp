class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        auto buildList = [](const vector<vector<int>> &edges)
        {
            vector<vector<int>> adj(edges.size() + 1);
            for (auto &e : edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            return adj;
        };

        function<int(const vector<vector<int>> &, int, int, int)> dfs =
            [&](const vector<vector<int>> &adj, int u, int p, int k) -> int
        {
            if (k < 0)
                return 0;
            int cnt = 1;
            for (int v : adj[u])
                if (v != p)
                    cnt += dfs(adj, v, u, k - 1);
            return cnt;
        };

        auto adj1 = buildList(edges1), adj2 = buildList(edges2);
        int n = adj1.size(), m = adj2.size(), maxiB = 0;
        vector<int> res(n);

        for (int i = 0; i < m; i++)
            maxiB = max(maxiB, dfs(adj2, i, -1, k - 1));
        for (int i = 0; i < n; i++)
            res[i] = dfs(adj1, i, -1, k) + maxiB;
        return res;
    }
};