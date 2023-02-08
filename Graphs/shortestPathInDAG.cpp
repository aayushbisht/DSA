class Solution
{
private:
    void topoLogicalSort(int src, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &visited)
    {
        visited[src] = 1;
        for (auto it : adj[src])
        {
            int v = it.first;
            if (!visited[v])
                topoLogicalSort(v, adj, st, visited);
        }
        st.push(src);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> visited(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
            if (!visited[i])
                topoLogicalSort(i, adj, st, visited);

        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!st.empty() && st.top() != 0)
            st.pop();
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }

        for (int i = 0; i < N; i++)
            if (dist[i] == 1e9)
                dist[i] = -1;
        return dist;
    }
};