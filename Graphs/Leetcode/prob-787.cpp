class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({src, {0, 0}}); //{node,{dist,level}}
        while (!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            if (level > k)
                continue;
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int weight = it.second;
                if (level <= k and dis + weight < dist[adjNode])
                {
                    dist[adjNode] = dis + weight;
                    q.push({adjNode, {dis + weight, level + 1}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};