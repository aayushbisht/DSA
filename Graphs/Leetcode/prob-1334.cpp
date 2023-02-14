class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int thresh)
        {
            vector<vector < int>> dist(n, vector<int> (n, 1e8));
            for(auto it : edges){
                dist[it[0]][it[1]] = it[2];
                dist[it[1]][it[0]] = it[2];
            }
            for (int i = 0; i < n; i++) {
                dist[i][i] = 0;
            }
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                       if(dist[i][k]!=1e8 and dist[k][j]!=1e8){
                           dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                       }
                    }
                }
            }
            int mini = INT_MAX;
            int count = 0;
            int ans;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]<=thresh) count++;
                }
                if(count<=mini){
                    mini = count;
                    ans = i;
                }
                count=0;
            }
            return ans;
        }
};