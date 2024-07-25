#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int V,vector<vector<int>> adj)
{
    vector<int> visited(V, 0);
    visited[0] = 1; // for node starting from zero

    queue<int> q;
    q.push(0);

    vector<int> bfsans;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsans.push_back(node);

        for(auto x : adj[node])
        {
            if(visited[x] == 0)
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    return bfsans;
}
int main()
{
    //enter number of vertex and edges
    int V,e;
    cin>>V>>e;
    vector<vector<int>> adj(V);    //create a adjacency list of side V
    for(int i = 0; i<e; i++)      // add all the edges into the list
    {
        int u,v;
        cin>>u>>v;

        //directed graph
        adj[u].push_back(v);

        //undirected graph
        // adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int> ans = bfs(V,adj);
    for(auto x : ans)
        cout<<x<<endl;
}