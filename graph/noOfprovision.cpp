
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int node, vector<vector<int>> adj, vector<int>&visited)
    {
        visited[node] = 1;
        for(int i = 0; i<adj[0].size(); i++)
        {
            if(visited[i] == 0 && adj[node][i] == 1)
            {
                dfs(i,adj,visited);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V,0);
        int ans = 0;

        for(int i = 0; i<V; i++)
        {
            
            if(visited[i] == 0)
            {
                ans++;
                dfs(i,adj,visited);
            }
        }
       
        return ans;
    }
};


int main() {

    int V,x;
    cin>>V;
        
    vector<vector<int>> adj;
    
    for(int i=0; i<V; i++)
    {
        vector<int> temp;
        for(int j=0; j<V; j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    
    Solution ob;
    cout << ob.numProvinces(adj,V) << endl;
    return 0;
}