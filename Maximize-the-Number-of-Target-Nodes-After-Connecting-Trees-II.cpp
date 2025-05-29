class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        const int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n), color2(m);

        auto calculateBipartiteCounts = [](const vector<vector<int>> &edges, vector<int> &colors) -> pair<int, int>
        {
            const int nodeCount = edges.size() + 1;
            vector<vector<int>> adj(nodeCount);

            for (const auto &edge : edges)
                adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

            function<int(int, int, int)> dfs = [&](int node, int parent, int depth) -> int
            {
                colors[node] = depth % 2;
                int evenDepthCount = (depth % 2 == 0) ? 1 : 0;

                for (int neighbor : adj[node])
                    if (neighbor != parent)
                        evenDepthCount += dfs(neighbor, node, depth + 1);

                return evenDepthCount;
            };

            int evenCount = dfs(0, -1, 0), oddCount = nodeCount - evenCount;
            return {evenCount, oddCount};
        };

        auto [evenCount1, oddCount1] = calculateBipartiteCounts(edges1, color1);
        auto [evenCount2, oddCount2] = calculateBipartiteCounts(edges2, color2);

        const int maxTree2Nodes = max(evenCount2, oddCount2);

        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = ((color1[i] == 0) ? evenCount1 : oddCount1) + maxTree2Nodes;

        return result;
    }
};