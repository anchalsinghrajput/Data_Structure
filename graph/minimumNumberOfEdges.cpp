#include<bits/stdc++.h>
using namespace std;
void minimumNumberOfEdge(unordered_map<int,vector<int>>& adj, unordered_map<int,int> &visited, int curNode)
{
    visited[curNode] = 1;
    queue<pair<int,int>> q;
    q.push({curNode,-1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto x : adj[node])
        {
            if(visited[x]==0)
            {
                q.push({x,node});
                visited[x] = 1;
            }
        }
    }
}

int main()
{
    int V;
    cin>>V;
    vector<int> vertices(V);
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> visited;
    for(int i=0; i<V; i++)
    {
        int vertex;
        cin>>vertex;
        vertices[i]=vertex;
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

    int node1,node2;
    cin>>node1>>node2;

    vector<int> visited2(V,0);

    minimumNumberOfEdge(adj,visited,node1);

    int count = 0;
    for(auto x : adj[node2])
    {
        if(visited[x] == 1)
        {
            count++;
        }
    }

    cout<<count;
}