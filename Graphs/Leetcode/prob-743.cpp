class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        pq.push({k,0});
        while(!pq.empty())
        {
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int weight = it.second;
                int adj = it.first;
                if(dis+weight<dist[adj])
                {
                    dist[adj] = dis+weight;
                    pq.push({adj,dist[adj]});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            maxi = max(maxi,dist[i]);
            if(dist[i]==1e9) return -1;
            cout<<dist[i]<<endl;
        }
        return maxi;
        
    }
};