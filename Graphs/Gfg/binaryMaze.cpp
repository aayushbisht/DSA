//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    vector<int> delta = {0, 1, 0, -1, 0};

public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;
        if (source.first == destination.first and source.second == destination.second)
            return 0;
        while (!q.empty())
        {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delta[i];
                int ncol = c + delta[i + 1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == destination.first and ncol == destination.second)
                        return dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends