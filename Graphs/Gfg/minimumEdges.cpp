//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
           vector<pair<int,int>>adj[n+1];
               for(auto it : edges){
                   adj[it[0]].push_back({it[1],0});
                   adj[it[1]].push_back({it[0],1});
               }
    
           vector<int>dist(n+1,1e8);
           deque<pair<int,int>>dq;
           dq.push_front({src,0});
           dist[src] = 0;
           while(!dq.empty()){
               int node = dq.front().first;
               int dis = dq.front().second;
               dq.pop_front();
               for(auto it : adj[node]){
                   int adjNode = it.first;
                   int weight = it.second;
                   if(dis+weight<dist[adjNode]){
                       dist[adjNode] = dis+weight;
                       if(weight)
                       dq.push_back({adjNode,dis+weight});
                       else
                        dq.push_front({adjNode,dis+weight});
                   }
               }
           }
           return dist[dst]==1e8?-1:dist[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends