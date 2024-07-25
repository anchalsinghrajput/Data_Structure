
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    
  public: 
  
    bool dfs(int node, vector<int>&visited, vector<int>&checkPath,vector<int> adj[])
    {
        visited[node] = 1;
        checkPath[node] = 1;
        for(auto x : adj[node])
        {
            
            if(visited[x] == 0)
            {
                if(dfs(x,visited,checkPath,adj) == true) return true;
            }
            else if(checkPath[x] == 1)
                return true;
        }
        checkPath[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
      vector<int> visited(V,0);
      vector<int>checkPath(V,0);
      
      for(int i = 0; i<V; i++)
      {
          if(visited[i] == 0)
          {
              if(dfs(i,visited,checkPath,adj) == true) return true;
          }
      }
      
      return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
