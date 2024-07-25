#include<bits/stdc++.h>
using namespace std;
bool isThereCycle(unordered_map<int,vector<int>>& adj, unordered_map<int,int> &visited, int curNode)
{
    visited[curNode] = 1;
    queue<pair<int,int>> q;
    q.push({curNode,-1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        // cout<<node<<endl;
        for(auto x : adj[node])
        {
            // cout<<parent<<":"<<x<<endl;
            if(visited[x]==0)
            {
                q.push({x,node});
                visited[x] = 1;
            }
            else if(parent != x)
            {
                return true;
            }
        }
    }

    return false;
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


    for(int i= 0; i<V; i++)
    {
        if(visited[vertices[i]] == 0)
        {
            if(isThereCycle(adj,visited,vertices[i]) == true)
            {
                cout<<true;
                exit(0);
            }
        }
    }    
    cout<<false;
}