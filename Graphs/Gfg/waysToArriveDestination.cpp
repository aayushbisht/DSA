//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        vector<pair<ll,ll>> adj[n+10];
        for(auto it:roads){
            adj[ll(it[0])].push_back({ll(it[1]),ll(it[2])});
            adj[ll(it[1])].push_back({ll(it[0]),ll(it[2])});
        }
        priority_queue<pair<ll, ll>,
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> dist(n,LLONG_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                ll adjNode= it.first;
                ll edW= it.second;
                if(dis+edW< dist[adjNode]){
                    dist[adjNode]=dis + edW;
                    ways[adjNode]=ways[node];
                    pq.push({dis+edW, adjNode});
                }
                else if(dis+edW==dist[adjNode]){
                    ways[adjNode]+=(ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends