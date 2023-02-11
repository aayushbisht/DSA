class Solution
{
public:
    vector<int> delta = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});

        while (!q.empty())
        {
            int eff = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if (r == n - 1 and c == m - 1)
                return eff;
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delta[i];
                int ncol = c + delta[i + 1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int newEff = max(abs(heights[nrow][ncol] - heights[r][c]), eff);
                    if (newEff < effort[nrow][ncol])
                    {
                        effort[nrow][ncol] = newEff;
                        q.push({newEff, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};