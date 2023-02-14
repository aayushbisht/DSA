//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isNegativeWeightCycle(int V, vector<vector<int>> edges)
    {
        vector<int> dist(V, 1e8);
        dist[0] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int src = it[0];
                int des = it[1];
                int w = it[2];
                if (dist[src] != 1e8 and dist[src] + w < dist[des])
                {
                    dist[des] = dist[src] + w;
                }
            }
        }
        for (auto it : edges)
        {
            int src = it[0];
            int des = it[1];
            int w = it[2];
            if (dist[src] != 1e8 and dist[src] + w < dist[des])
            {
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends