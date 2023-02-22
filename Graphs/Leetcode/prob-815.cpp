class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = 1e6+10;
        vector<int>adj[n];
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }
        }
        vector<int>busVis(501,0),routeVis(n,0);
        queue<pair<int,int>>q;
        q.push({source,0});
        while(!q.empty()){
            int stop = q.front().first;
            int count = q.front().second;
            q.pop();
            if(target == stop) return count;
            for(auto it : adj[stop]){
                if(busVis[it]) continue;
                for(auto x : routes[it]){
                    if(routeVis[x])continue;
                    routeVis[x] = 1;
                    q.push({x,count+1});
                }
                busVis[it] = 1;
            }
        }
        return -1;
    }
};