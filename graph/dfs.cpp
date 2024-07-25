#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> adj, vector<int>&visited, vector<int>&ans)
{
    visited[node] = 1;
    ans.push_back(node);
    for(auto x : adj[node])
    {
        if(visited[x]==0)
        {
            dfs(x,adj,visited,ans);
        }
    }
}

int main()
{
    int V,e;
    cin>>V>>e;

    vector<vector<int>> adj(V);

    for(int i = 0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V,0);
    vector<int>ans;
    dfs(0,adj,visited,ans);

    for(auto x : ans)
        cout<<x<<endl;

}