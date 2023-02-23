class Solution {
public:
    int timer = 0;
    using vi = vector<int>;
    void dfs(int u,int p,vi&low,vi&disc,vi&vis,vector<vi>&ans,vi adj[]){
        vis[u] = 1;
        low[u] = disc[u] = ++timer;
        for(auto v : adj[u]){
            if(v==p) continue;
            if(!vis[v]){
                dfs(v,u,low,disc,vis,ans,adj);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u]) ans.push_back({u,v});
            }
            else low[u] = min(low[u],low[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vi adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vi>ans;
        vi low(n,-1),disc(n,-1),vis(n,0);
        dfs(0,-1,low,disc,vis,ans,adj);
        return ans;
    }
};