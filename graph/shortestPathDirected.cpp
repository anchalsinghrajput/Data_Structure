//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int> dis(N,-1);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        dis[src] = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int path = q.front().second;
            
            for(auto x : adj[node])
            {
                if(dis[x] == -1)
                {
                    q.push({x,path+1});
                    dis[x] = path+1;
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends