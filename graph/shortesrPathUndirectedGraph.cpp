//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

    // void dfs(int node, vector<int> &vis,vector<vector<pair<int,int>>>&adj, stack<int> topo)
    // {
    //     vis[node] = 1;
    //     for(auto x : adj[node])
    //     {
    //         if(vis[x.first] == 0)
    //         {
    //             dfs(x.first,vis,adj,topo);
    //         }
    //     }
    //     topo.push(node);
    // }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
         vector<vector<pair<int,int>>> adj;
         for(int i = 0; i<M; i++)
         {
             int u = edges[i][0];
             int v = edges[i][1];
             int wt = edges[i][2];
             adj[u].push_back({v,wt});
         }
         

         for(auto x : adj)
         {
            for(auto y : x)
            {
                cout<<y.first<<" : "<<y.second<<endl;
            }
         }
        // stack<int> toposort;
        // vector<int> vis(N,0);
        // for(int i = 0; i<N; i++)
        // {
        //     if(vis[i] == 0)
        //     {
        //         dfs(i, vis, adj, toposort);
        //     }
        // }
        
        // for(int i = 0; !toposort.empty(); i++){
        //     cout<<toposort.top()<<" ";
        //     toposort.pop();
        // }
        vector<int> dis(N,INT_MAX);
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends