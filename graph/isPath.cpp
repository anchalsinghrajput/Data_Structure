#include<bits/stdc++.h>
using namespace std;
bool isTherePath(unordered_map<int,vector<int>>& adj, unordered_map<int,int> &visited, int source, int destination)
{
    visited[source] = 1;
    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto x : adj[node])
        {
            if(visited[x]==0)
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }

    return visited[destination];
}

int main()
{
    int V;
    cin>>V;
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> visited;
    for(int i=0; i<V; i++)
    {
        int vertex;
        cin>>vertex;
        adj[vertex];
        visited[vertex] = 0;
    }

    int e;
    cin>>e;
    for(int i = 0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int source, destination;
    cin>>source>>destination;

    cout<<isTherePath(adj,visited,source,destination);
    
}