class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
                
        int curr = node1, d = 0;
        while (curr != -1 && dist1[curr] == -1) {
            dist1[curr] = d++;
            curr = edges[curr];
        }
                
        curr = node2;
        d = 0;
        while (curr != -1 && dist2[curr] == -1) {
            dist2[curr] = d++;
            curr = edges[curr];
        }
                
        int result = -1, minMaxDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minMaxDist) {
                    minMaxDist = maxDist;
                    result = i;
                }
            }
        }
                
        return result;
    }
};