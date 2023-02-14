//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int thresh) {
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


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends