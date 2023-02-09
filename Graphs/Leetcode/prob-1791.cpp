class Solution
{
    public:
        int findCenter(vector<vector < int>> &edges)
        {
            unordered_map<int, vector < int>> adj;

            for (auto &i: edges)
            {
                vector<int> v = i;
                adj[v[0]].push_back(v[1]);
                adj[v[1]].push_back(v[0]);
            }

            for (auto &x: adj)
            {
                if (x.second.size() == edges.size()) return x.first;
            }
            return -1;
        }
};