class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]), indegree[e[1]]++;

        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i), count[i][colors[i] - 'a'] = 1;

        int visited = 0;
        int result = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            visited++;

            result = max(result, *max_element(count[curr].begin(), count[curr].end()));

            for (int next : adj[curr])
            {
                for (int i = 0; i < 26; i++)
                    count[next][i] = max(count[next][i],
                                         count[curr][i] + (i == colors[next] - 'a' ? 1 : 0));
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return visited == n ? result : -1;
    }
};