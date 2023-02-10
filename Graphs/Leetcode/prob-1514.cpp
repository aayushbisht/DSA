class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int k, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        priority_queue<pair<int,double>>pq;
        vector<double>prob(n,0.0);
        prob[k] = 1.0;
        pq.push({k,1.0});
        while(!pq.empty())
        {
            int node = pq.top().first;
            double dis = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                double weight = it.second;
                int adj = it.first;
                if(dis*weight>prob[adj])
                {
                    prob[adj] = dis*weight;
                    pq.push({adj,prob[adj]});
                }
            }
        }
        
        return prob[end];
        
    }
};