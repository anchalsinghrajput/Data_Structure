#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool dfs(int i, vector<int>& visited, vector<int> adj[], int color)
{
    visited[i] = color;
    for(auto x : adj[i])
    {
        if(visited[x] == -1)
        {
            if(dfs(x,visited,adj,!color) == false) return false;
            cout<<x<< " : "<<visited[x] << " color = " << color<<endl;
        }
        else if(visited[x] == color) 
        {
            
            return false;
        }
        
    }
    return true;
    
}
bool isBipartite(int V, vector<int>adj[]){
    vector<int> visited(V,-1);
    for(int i = 0; i<V; i++)
    {
        if(visited[i] == -1)
        {
            if(dfs(i,visited,adj,0) == false) return false;
        }
    }
    
    return true;
}
	

};

int main(){
	int V, E;
	cin >> V >> E;
	vector<int>adj[V];
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Solution obj;
	bool ans = obj.isBipartite(V, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	return 0;
}