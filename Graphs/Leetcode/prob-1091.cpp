class Solution
{
public:
    vector<int> delta{0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        q.push({1, {0, 0}});
        if (grid[0][0] == 1)
            return -1;
        if (grid[0][0] == 0 and n == 1)
            return 1;
        while (!q.empty())
        {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();
            for (int i = 0; i < 9; i++)
            {
                int nrow = r + delta[i];
                int ncol = c + delta[i + 1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == (n - 1) && ncol == (n - 1))
                        return dis + 1;
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};